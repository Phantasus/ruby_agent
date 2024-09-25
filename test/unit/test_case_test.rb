# Ruby Agent -- a finger exercise in injection
# Copyright (C) 2024 Josef Philip Bernhart

require "test_interface"

class TestCaseTest < RubyAgent::TestCase
  def test_trueness
    assert_equal 1, 1
  end

  def test_falseness
    refute_equal 1, 2
  end
end
