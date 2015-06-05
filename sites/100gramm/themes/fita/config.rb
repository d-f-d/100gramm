##
## This file is only needed for Compass/Sass integration. If you are not using
## Compass, you may safely ignore or delete this file.
##
## If you'd like to learn more about Sass and Compass, see the sass/README.txt
## file for more information.
##

# Change this to :production when ready to deploy the CSS to the live server.
environment = :work
#environment = :development

# Location of the theme's resources.
css_dir = "css"
sass_dir = "sass"
images_dir = "images"
fonts_dir = "fonts"
generated_images_dir = images_dir + "/generated"
javascripts_dir = "js"

# Require any additional compass plugins installed on your system.
#require 'compass-normalize'
require 'compass/import-once/activate'
require 'sass-globbing'
require 'toolkit'
require 'json'

##
## You probably don't need to edit anything below this.
##

# You can select your preferred output style here (:expanded, :nested, :compact
# or :compressed).
output_style = (environment == :development) ? :expanded : :expanded

# To enable relative paths to assets via compass helper functions. Since Drupal
# themes can be installed in multiple locations, we don't need to worry about
# the absolute path to the theme from the server omega.
relative_assets = true

# Conditionall enable line comments when in development mode.
line_comments = (environment == :development) ? true : false

# Output debugging info in development mode.
sass_options = (environment == :development) ? {:debug_info => true} : {}

sass_options = {:unix_newlines => true}
asset_cache_buster :none

module Sass::Script::Functions
    def SassyExport(path, map, pretty, debug)

        def opts(value)
            value.options = options
            value
        end

        # unquote strings
        def u(s)
            unquote(s)
        end

        # recursive parse to array
        def recurs_to_a(array)
            if array.is_a?(Array)
                array.map do | l |
                    case l
                    when Sass::Script::Value::Map
                        # if map, recurse to hash
                        l = recurs_to_h(l)
                    when Sass::Script::Value::List
                        # if list, recurse to array
                        l = recurs_to_a(l)
                    when Sass::Script::Value::Bool
                        # convert to bool
                        l = l.to_bool
                    when Sass::Script::Value::Number
                        # if it's a unitless number, convert to ruby val
                        # else convert to string
                        l.unitless? ? l = l.value : l = u(l)
                    when Sass::Script::Value::Color
                        # get hex/rgba value for color
                        l = l.inspect
                    else
                        # convert to string
                        l = u(l)
                    end
                    l
                end
            else
                recurs_to_a(array.to_a)
            end
        end

        # recursive parse to hash
        def recurs_to_h(hash)
            if hash.is_a?(Hash)
                hash.inject({}) do | h, (k, v) |
                    case v
                    when Sass::Script::Value::Map
                        # if map, recurse to hash
                        h[u(k)] = recurs_to_h(v)
                    when Sass::Script::Value::List
                        # if list, recurse to array
                        h[u(k)] = recurs_to_a(v)
                    when Sass::Script::Value::Bool
                        # convert to bool
                        h[u(k)] = v.to_bool
                    when Sass::Script::Value::Number
                        # if it's a unitless number, convert to ruby val
                        # else convert to string
                        v.unitless? ? h[u(k)] = v.value : h[u(k)] = u(v)
                    when Sass::Script::Value::Color
                        # get hex/rgba value for color
                        h[u(k)] = v.inspect
                    else
                        # convert to string
                        h[u(k)] = u(v)
                    end
                    h
                end
            else
                recurs_to_h(hash.to_h)
            end
        end

        # assert types
        assert_type path, :String, :path
        assert_type map, :Map, :map
        assert_type pretty, :Bool, :pretty
        assert_type debug, :Bool, :debug

        # parse to bool
        pretty = pretty.to_bool
        debug = debug.to_bool

        # parse to string
        path = unquote(path).to_s

        # define root path up to current working directory
        root = Dir.pwd

        # define dir path
        dir_path = root
        dir_path += path

        # get filename
        filename = File.basename(dir_path, ".*")

        # get extension
        ext = File.extname(path)

        # normalize windows path
        dir_path = Sass::Util.pathname(dir_path)

        # check if directory exists, if not make directory
        dir = File.dirname(dir_path)

        unless File.exists?(dir)
            FileUtils.mkdir_p(dir)
            puts "Directory was not found. Created new directory: #{dir}"
        end

        # get map values
        map = opts(Sass::Script::Value::Map.new(map.value))

        # recursive convert map to hash
        hash = recurs_to_h(map)

        # convert hash to pretty json if pretty
        pretty ? json = JSON.pretty_generate(hash) : json = JSON.generate(hash)

        # if we're turning it straight to js put a variable name in front
        json = "var " + filename + " = " + json if ext == '.js'

        # define flags
        flag = 'w'
        flag = 'wb' if Sass::Util.windows? && options[:unix_newlines]

        # open file [create new file if file does not exist], write string to root/path/to/filename.json
        File.open("#{dir_path}", flag) do |file|
            file.set_encoding(json.encoding) unless Sass::Util.ruby1_8?
            file.print(json)
        end

        # define message
        debug_msg = "#{ext == '.json' ? 'JSON' : 'JavaScript'} was successfully exported to #{dir_path}"

        # print path string if debug
        puts debug_msg if debug

        # return succcess string
        opts(Sass::Script::Value::String.new(debug_msg))
    end
    declare :SassyExport, [:path, :map, :pretty, :debug]
end
