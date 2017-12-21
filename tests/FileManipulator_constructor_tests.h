/**
 * @file FileManipulator_constructor_tests.cpp
 *
 * @brief
 * Unit tests for FileManipulator constructor
 *
 */

#ifndef _FILEMANIPULATOR_CONSTRUCTOR_TESTS_H_
#define _FILEMANIPULATOR_CONSTRUCTOR_TESTS_H_

#include "FileManipulator/FileManipulator.h"
#include "gtest/gtest.h"

namespace jayacode
{

  namespace filemanipulator
  {

    namespace tests
    {
      class FileManipulator_constructor_tests_1 : public ::testing::Test
      {
      public:
        FileManipulator_constructor_tests_1();
        virtual ~FileManipulator_constructor_tests_1();

        virtual void SetUp(void);
        virtual void TearDown(void);
        
        void PrintTo(const FileManipulator_constructor_tests_1&, ::std::ostream*);

        static constexpr char const *FILE1_FILENAME = "../test-vectors/file1.cpp";
        static constexpr unsigned int FILE1_LINENUM = 119;
        static constexpr unsigned int FILE1_SIZE = 4170;
        static constexpr char const *BIGFILE1_FILENAME = "../test-vectors/bigfile1.cpp";
        static constexpr unsigned int BIGFILE1_LINENUM = 30482;
        static constexpr unsigned int BIGFILE1_SIZE = 1077823;
        static constexpr char const *EMPTYFILE1_FILENAME = "../test-vectors/emptyfile1.cpp";
        static constexpr unsigned int EMPTYFILE1_LINENUM = 0;
        static constexpr unsigned int EMPTYFILE1_SIZE = 0;

        static constexpr char const *FILE2_FILENAME = "../test-vectors/file2.ast";
        static constexpr unsigned int FILE2_LINENUM = 45;
        static constexpr unsigned int FILE2_SIZE = 3638;
        static constexpr char const *BIGFILE2_FILENAME = "../test-vectors/bigfile2.ast";
        static constexpr unsigned int BIGFILE2_LINENUM = 6047;
        static constexpr unsigned int BIGFILE2_SIZE = 567008;
        static constexpr char const *EMPTYFILE2_FILENAME = "../test-vectors/emptyfile2.ast";
        static constexpr unsigned int EMPTYFILE2_LINENUM = 0;
        static constexpr unsigned int EMPTYFILE2_SIZE = 0;
      };
      
    } // ! namespace tests
    
  } // ! namespace filemanipulator
  
} // ! namespace jayacode

#endif /* ! _FILEMANIPULATOR_CONSTRUCTOR_TESTS_H_ */

