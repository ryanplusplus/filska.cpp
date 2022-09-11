set_languages('c++20')

add_requires('conan::cpputest/4.0', { alias = 'cpputest' })

target('filska')
  set_kind('binary')
  add_includedirs('src')
  add_files('src/**.cpp')
  add_packages('csv-parser')
  add_rules('mode.check', 'mode.release')
  set_warnings('everything', 'error')

target('test')
  set_kind('binary')
  add_includedirs('src')
  add_files('src/*/**.cpp')
  add_files('test/test_runner.cpp')
  add_files('test/src/**.cpp')
  add_packages('cpputest', 'csv-parser')
  add_rules('mode.check')
  set_warnings('everything', 'error')
  after_build(function(target)
    os.exec(target:targetfile())
  end)
