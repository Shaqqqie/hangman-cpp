add_test( [==[Letter exists in word]==] D:/Projects/hangman-cpp/build/hangman_tests.exe [==[Letter exists in word]==]  )
set_tests_properties( [==[Letter exists in word]==] PROPERTIES WORKING_DIRECTORY D:/Projects/hangman-cpp/build SKIP_RETURN_CODE 4)
set( hangman_tests_TESTS [==[Letter exists in word]==])
