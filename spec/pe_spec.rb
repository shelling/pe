require 'spec_helper'

describe PE do
    subject { PE::Agent.new }
    its(:vendor)  { should have(12).characters }
    its(:cpuname) { should have(47).characters }
end
