require 'spec_helper'

describe PE do
    subject { PE::Agent.new }
    it { should have(12).vendor }
    it { should have(47).cpuname }
end
