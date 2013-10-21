# coding: utf-8
lib = File.expand_path('../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require 'pe/version'

Gem::Specification.new do |spec|
  spec.name          = "pe"
  spec.version       = Pe::VERSION
  spec.authors       = ["shelling"]
  spec.email         = ["navyblueshellingford@gmail.com"]
  spec.description   = %q{The Parallel Executor and Queue System targets MPI enviroment.}
  spec.summary       = %q{Parallel Executor}
  spec.homepage      = ""
  spec.license       = "MIT"

  spec.files         = `git ls-files`.split($/)
  spec.executables   = spec.files.grep(%r{^bin/}) { |f| File.basename(f) }
  spec.test_files    = spec.files.grep(%r{^(test|spec|features)/})
  spec.require_paths = ["lib"]
  spec.extensions    = %w[ext/pe/extconf.rb]

  spec.add_development_dependency "bundler", "~> 1.3"
  spec.add_development_dependency "rake"
end
