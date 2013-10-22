require "thor"

module PE
    class Cmd < Thor
        desc "master", "start master"
        def master
            require "pe/master"
            app = PE::Master.new
            if defined?(Unicorn::HttpServer)
                Unicorn::HttpServer.new(app).start.join
            else
                options = {app: app}
                options[:server] = "thin" if defined?(Thin)
                Rack::Server.start(options)
            end
        end

        desc "version", "print version"
        def version
            puts PE::VERSION
        end
    end
end
