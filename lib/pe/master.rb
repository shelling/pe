require "sinatra/base"

begin
    require "unicorn"
rescue LoadError
    begin
        require "thin"
    rescue LoadError
        require "rack"
    end
end

module PE
    class Master < Sinatra::Base
        enable :logging

        get "/" do
        end

        post "/" do
        end
    end
end
