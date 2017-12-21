/**
 * @file FileManipulator_constructor_tests.cpp
 *
 * @brief
 * Unit tests for FileManipulator constructor
 *
 */

#include "FileManipulator_constructor_tests.h"



namespace jayacode
{

  namespace filemanipulator
  {

    namespace tests
    {
      constexpr unsigned int FileManipulator_constructor_tests_1::FILE1_LINENUM;
      constexpr unsigned int FileManipulator_constructor_tests_1::BIGFILE1_LINENUM;
      constexpr unsigned int FileManipulator_constructor_tests_1::EMPTYFILE1_LINENUM;
      constexpr unsigned int FileManipulator_constructor_tests_1::FILE2_LINENUM;
      constexpr unsigned int FileManipulator_constructor_tests_1::BIGFILE2_LINENUM;
      constexpr unsigned int FileManipulator_constructor_tests_1::EMPTYFILE2_LINENUM;

      constexpr unsigned int FileManipulator_constructor_tests_1::FILE1_SIZE;
      constexpr unsigned int FileManipulator_constructor_tests_1::BIGFILE1_SIZE;
      constexpr unsigned int FileManipulator_constructor_tests_1::EMPTYFILE1_SIZE;
      constexpr unsigned int FileManipulator_constructor_tests_1::FILE2_SIZE;
      constexpr unsigned int FileManipulator_constructor_tests_1::BIGFILE2_SIZE;
      constexpr unsigned int FileManipulator_constructor_tests_1::EMPTYFILE2_SIZE;

      FileManipulator_constructor_tests_1::FileManipulator_constructor_tests_1()
      {
      }

      FileManipulator_constructor_tests_1::~FileManipulator_constructor_tests_1()
      {
      }
      
      void
      FileManipulator_constructor_tests_1::SetUp(void)
      {
      }

      void
      FileManipulator_constructor_tests_1::TearDown(void)
      {
      }

      void
      FileManipulator_constructor_tests_1::PrintTo(const FileManipulator_constructor_tests_1 &instance,
                                                   ::std::ostream *os)
      {
      }

      TEST_F(FileManipulator_constructor_tests_1, DefaultConstructor)
      {
        FileManipulator fm;
        fm.open(FILE2_FILENAME);
        EXPECT_TRUE(fm.is_open() || !fm.is_open());
        fm.close();
      }

      TEST_F(FileManipulator_constructor_tests_1, DefaultPtrConstructor)
      {
        FileManipulator *pfm = new FileManipulator();
        pfm->open(FILE1_FILENAME);
        EXPECT_TRUE(pfm->is_open() || !pfm->is_open());
        pfm->close();
        delete pfm;
      }

      TEST_F(FileManipulator_constructor_tests_1, ExplicitConstructor)
      {
        FileManipulator fm(FILE2_FILENAME);
        EXPECT_TRUE(fm.is_open() || !fm.is_open());
        fm.close();
      }

      TEST_F(FileManipulator_constructor_tests_1, ExplicitPtrConstructor)
      {
        FileManipulator *pfm = new FileManipulator(FILE1_FILENAME);
        EXPECT_TRUE(pfm->is_open() || !pfm->is_open());
        pfm->close();
        delete pfm;
      }

      TEST_F(FileManipulator_constructor_tests_1, PtrDestructor)
      {
        FileManipulator *pfm = new FileManipulator(FILE1_FILENAME);
        EXPECT_TRUE(pfm->is_open() || !pfm->is_open());
        pfm->close();
        delete pfm;
      }

      TEST_F(FileManipulator_constructor_tests_1, NotOpenLogicException)
      {
        FileManipulator fm;
        EXPECT_THROW(fm[0], std::logic_error);
        fm.close();
      }

      TEST_F(FileManipulator_constructor_tests_1, CreateLineMapping)
      {
        FileManipulator fm1(FILE1_FILENAME);
        EXPECT_TRUE(fm1.is_open());
        fm1.create_line_number_mapping();
        EXPECT_EQ(fm1.get_number_of_lines(),
                  jayacode::filemanipulator::tests::FileManipulator_constructor_tests_1::FILE1_LINENUM);
        fm1.close();
        fm1.reset_line_number_mapping();

        FileManipulator fm2(FILE2_FILENAME);
        EXPECT_TRUE(fm2.is_open());
        fm2.create_line_number_mapping();
        EXPECT_EQ(fm2.get_number_of_lines(),
                  FileManipulator_constructor_tests_1::FILE2_LINENUM);
        fm2.close();
        fm2.reset_line_number_mapping();

        FileManipulator fm3(BIGFILE1_FILENAME);
        EXPECT_TRUE(fm3.is_open());
        fm3.create_line_number_mapping();
        EXPECT_EQ(fm3.get_number_of_lines(),
                  FileManipulator_constructor_tests_1::BIGFILE1_LINENUM);
        fm3.close();
        fm3.reset_line_number_mapping();

        fm1.open(BIGFILE2_FILENAME);
        EXPECT_TRUE(fm1.is_open());
        fm1.create_line_number_mapping();
        EXPECT_EQ(fm1.get_number_of_lines(),
                  FileManipulator_constructor_tests_1::BIGFILE2_LINENUM);
        fm1.close();
        fm1.reset_line_number_mapping();

        fm2.open(EMPTYFILE1_FILENAME);
        EXPECT_TRUE(fm2.is_open());
        fm2.create_line_number_mapping();
        EXPECT_EQ(fm2.get_number_of_lines(),
                  FileManipulator_constructor_tests_1::EMPTYFILE1_LINENUM);
        fm2.close();
        fm2.reset_line_number_mapping();

        fm3.open(EMPTYFILE2_FILENAME);
        EXPECT_TRUE(fm3.is_open());
        fm3.create_line_number_mapping();
        EXPECT_EQ(fm3.get_number_of_lines(),
                  FileManipulator_constructor_tests_1::EMPTYFILE2_LINENUM);
        fm3.close();
        fm3.reset_line_number_mapping();
      }

      TEST_F(FileManipulator_constructor_tests_1, CheckSize)
      {
        FileManipulator fm1(FILE1_FILENAME);
        EXPECT_TRUE(fm1.is_open());
        fm1.create_line_number_mapping();
        EXPECT_EQ(fm1.size(),
                  jayacode::filemanipulator::tests::FileManipulator_constructor_tests_1::FILE1_SIZE);
        fm1.close();
        fm1.reset_line_number_mapping();

        FileManipulator fm2(FILE2_FILENAME);
        EXPECT_TRUE(fm2.is_open());
        fm2.create_line_number_mapping();
        EXPECT_EQ(fm2.size(),
                  FileManipulator_constructor_tests_1::FILE2_SIZE);
        fm2.close();
        fm2.reset_line_number_mapping();

        FileManipulator fm3(BIGFILE1_FILENAME);
        EXPECT_TRUE(fm3.is_open());
        fm3.create_line_number_mapping();
        EXPECT_EQ(fm3.size(),
                  FileManipulator_constructor_tests_1::BIGFILE1_SIZE);
        fm3.close();
        fm3.reset_line_number_mapping();

        fm1.open(BIGFILE2_FILENAME);
        EXPECT_TRUE(fm1.is_open());
        fm1.create_line_number_mapping();
        EXPECT_EQ(fm1.size(),
                  FileManipulator_constructor_tests_1::BIGFILE2_SIZE);
        fm1.close();
        fm1.reset_line_number_mapping();

        fm2.open(EMPTYFILE1_FILENAME);
        EXPECT_TRUE(fm2.is_open());
        fm2.create_line_number_mapping();
        EXPECT_EQ(fm2.size(),
                  FileManipulator_constructor_tests_1::EMPTYFILE1_SIZE);
        fm2.close();
        fm2.reset_line_number_mapping();

        fm3.open(EMPTYFILE2_FILENAME);
        EXPECT_TRUE(fm3.is_open());
        fm3.create_line_number_mapping();
        EXPECT_EQ(fm3.size(),
                  FileManipulator_constructor_tests_1::EMPTYFILE2_SIZE);
        fm3.close();
        fm3.reset_line_number_mapping();
      }

      TEST_F(FileManipulator_constructor_tests_1, UseLineMapping)
      {
        FileManipulator fm1(FILE1_FILENAME);
        EXPECT_TRUE(fm1.is_open());
        fm1.create_line_number_mapping();
        EXPECT_EQ(fm1.get_number_of_lines(),
                  jayacode::filemanipulator::tests::FileManipulator_constructor_tests_1::FILE1_LINENUM);

        unsigned ln = 1;
        EXPECT_STREQ(fm1[ln++].c_str(), "/*-------------------------------Identification-------------------------------*/");
        EXPECT_STREQ(fm1[ln++].c_str(), "/**                           Sardane EasyDoc 02.1                           **/");
        EXPECT_STREQ(fm1[ln++].c_str(), "#ifndef LINT");
        EXPECT_STREQ(fm1[ln++].c_str(), "#define __WATINCLUDE__ \"file1.cpp\"");
        EXPECT_STREQ(fm1[ln++].c_str(), "#ifdef __TIMESTAMP__");
        EXPECT_STREQ(fm1[ln++].c_str(), "#define WhatStampGIVMiseEnFormeEpj_pc \"@(#)SARDANE $Revision:   3.132  $	GIVMiseEnFormeEpj.pc	\"\"(\"__TIMESTAMP__\"-\"__DATE__\" \"__TIME__\")\"");
        EXPECT_STREQ(fm1[ln++].c_str(), "#endif	/* __TIMESTAMP__ */");
        EXPECT_STREQ(fm1[ln++].c_str(), "");
        EXPECT_STREQ(fm1[ln++].c_str(), "/*----------------------------------Includes----------------------------------*/");
        EXPECT_STREQ(fm1[ln++].c_str(), "#include <stdio.h>");
        EXPECT_STREQ(fm1[ln++].c_str(), "#include <stdlib.h>");
        EXPECT_STREQ(fm1[ln++].c_str(), "#include <ctype.h>");
        EXPECT_STREQ(fm1[ln++].c_str(), "#include <errno.h>");
        EXPECT_STREQ(fm1[ln++].c_str(), "#include <time.h>");
        EXPECT_STREQ(fm1[ln++].c_str(), "#include <sys/time.h>");
        EXPECT_STREQ(fm1[ln++].c_str(), "#include <memory.h>");
        EXPECT_STREQ(fm1[ln++].c_str(), "#include <sys/types.h>");
        EXPECT_STREQ(fm1[ln++].c_str(), "#include <sys/stat.h>");
        EXPECT_STREQ(fm1[ln++].c_str(), "#include <string.h>");
        EXPECT_STREQ(fm1[ln++].c_str(), "#include <iconv.h>");
        EXPECT_STREQ(fm1[ln++].c_str(), "");
        EXPECT_STREQ(fm1[ln++].c_str(), "/*----Fonction----------------------------------------------------------------*/");
        EXPECT_STREQ(fm1[ln++].c_str(), "/*                                                                            */");
        EXPECT_STREQ(fm1[ln++].c_str(), "/* Fonction  : GIVCodeClient                                                  */");
        EXPECT_STREQ(fm1[ln++].c_str(), "/*----------------------------------------------------------------------------*/");
        EXPECT_STREQ(fm1[ln++].c_str(), "int4 GIVCodeClient ( char *cClient, int4 lg_chp )");
        EXPECT_STREQ(fm1[ln++].c_str(), "{");
        EXPECT_STREQ(fm1[ln++].c_str(), "  int4 iLong = 0;");
        EXPECT_STREQ(fm1[ln++].c_str(), "  int4 iVal,i = 0;");
        EXPECT_STREQ(fm1[ln++].c_str(), "  int4 iCodRet = (int4)GWCCodeOK;");
        EXPECT_STREQ(fm1[ln++].c_str(), "  char client_decode[14+1]=\"\";  /* numlo ou IG decode pr bloc de parution */");
        EXPECT_STREQ(fm1[ln++].c_str(), "");
        EXPECT_STREQ(fm1[ln++].c_str(), "  for (i=0;i<lg_chp;i++)");
        EXPECT_STREQ(fm1[ln++].c_str(), "  {");
        EXPECT_STREQ(fm1[ln++].c_str(), "    if ( (cClient[i] >= giv_Min) && (cClient[i] <= giv_Max ))");
        EXPECT_STREQ(fm1[ln++].c_str(), "    {");
        EXPECT_STREQ(fm1[ln++].c_str(), "      strcpy (client_decode, cClient);");
        EXPECT_STREQ(fm1[ln++].c_str(), "      break;");
        EXPECT_STREQ(fm1[ln++].c_str(), "    }");
        EXPECT_STREQ(fm1[ln++].c_str(), "  }");
        EXPECT_STREQ(fm1[ln++].c_str(), "");
        EXPECT_STREQ(fm1[ln++].c_str(), "  if (lg_chp == i)");
        EXPECT_STREQ(fm1[ln++].c_str(), "  {");
        EXPECT_STREQ(fm1[ln++].c_str(), "    while (iLong < lg_chp )");
        EXPECT_STREQ(fm1[ln++].c_str(), "    {");
        EXPECT_STREQ(fm1[ln++].c_str(), "      iVal = 0;");
        EXPECT_STREQ(fm1[ln++].c_str(), "      while (((nat1)(cClient[iLong]) != givtcCLIENTLO[iVal]) && (256 != iVal))");
        EXPECT_STREQ(fm1[ln++].c_str(), "      {");
        EXPECT_STREQ(fm1[ln++].c_str(), "        iVal++;");
        EXPECT_STREQ(fm1[ln++].c_str(), "      }");
        EXPECT_STREQ(fm1[ln++].c_str(), "      if ( iVal == 256)");
        EXPECT_STREQ(fm1[ln++].c_str(), "      {");
        EXPECT_STREQ(fm1[ln++].c_str(), "        GWTTrace (GWT_NIV_FONCT,");
        EXPECT_STREQ(fm1[ln++].c_str(), "                  (\"Erreur ne retrouve pas la valeur ...\\n\"));");
        EXPECT_STREQ(fm1[ln++].c_str(), "        iCodRet = (int4)GWCCodeKO ;");
        EXPECT_STREQ(fm1[ln++].c_str(), "      }");
        EXPECT_STREQ(fm1[ln++].c_str(), "      client_decode[(iLong*2)+1] = (char)((iVal % giv_DIV_PAR_DIX) + '0');");
        EXPECT_STREQ(fm1[ln++].c_str(), "      iVal = iVal / giv_DIV_PAR_DIX;");
        EXPECT_STREQ(fm1[ln++].c_str(), "      client_decode[(iLong*2)] = (char)((iVal % giv_DIV_PAR_DIX) + '0');");
        EXPECT_STREQ(fm1[ln++].c_str(), "      iLong++;");
        EXPECT_STREQ(fm1[ln++].c_str(), "");
        EXPECT_STREQ(fm1[ln++].c_str(), "    }");
        EXPECT_STREQ(fm1[ln++].c_str(), "  }");
        EXPECT_STREQ(fm1[ln++].c_str(), "  GWTTrace (GWT_NIV_FONCT,");
        EXPECT_STREQ(fm1[ln++].c_str(), "            ( \"client_decode = %s\\n\", client_decode ));");
        EXPECT_STREQ(fm1[ln++].c_str(), "  strcpy ( GIVtcClientDecode,client_decode);");
        EXPECT_STREQ(fm1[ln++].c_str(), "");
        EXPECT_STREQ(fm1[ln++].c_str(), "  return(iCodRet);");
        EXPECT_STREQ(fm1[ln++].c_str(), "");
        EXPECT_STREQ(fm1[ln++].c_str(), "}");
        EXPECT_STREQ(fm1[ln++].c_str(), "/*---------------------fin fonction-------------------------------------------*/");
        EXPECT_STREQ(fm1[ln++].c_str(), "");
        EXPECT_STREQ(fm1[ln++].c_str(), "");
        EXPECT_STREQ(fm1[ln++].c_str(), "/*----Fonction----------------------------------------------------------------*/");
        EXPECT_STREQ(fm1[ln++].c_str(), "/*                                                                            */");
        EXPECT_STREQ(fm1[ln++].c_str(), "/* Fonction  : givReprise ()                                                  */");
        EXPECT_STREQ(fm1[ln++].c_str(), "/*                                                                            */");
        EXPECT_STREQ(fm1[ln++].c_str(), "/* But       : offset de reprise                                              */");
        EXPECT_STREQ(fm1[ln++].c_str(), "/*                                                                            */");
        EXPECT_STREQ(fm1[ln++].c_str(), "/*                                                                            */");
        EXPECT_STREQ(fm1[ln++].c_str(), "/*                                                                            */");
        EXPECT_STREQ(fm1[ln++].c_str(), "/* Entree(s) :                                                                */");
        EXPECT_STREQ(fm1[ln++].c_str(), "/*                                                                            */");
        EXPECT_STREQ(fm1[ln++].c_str(), "/* Sortie(s) : OK ou KO                                                       */");
        EXPECT_STREQ(fm1[ln++].c_str(), "/*                                                                            */");
        EXPECT_STREQ(fm1[ln++].c_str(), "/* Portable  : Transparent                                                    */");
        EXPECT_STREQ(fm1[ln++].c_str(), "/*                                                                            */");
        EXPECT_STREQ(fm1[ln++].c_str(), "/*----------------------------------------------------------------------------*/");
        EXPECT_STREQ(fm1[ln++].c_str(), "");
        EXPECT_STREQ(fm1[ln++].c_str(), "static int4 givReprise (void)");
        EXPECT_STREQ(fm1[ln++].c_str(), "{");
        EXPECT_STREQ(fm1[ln++].c_str(), "  int4 iCodRet = GWCCodeOK;     /* Code retour de la fonction */");
        EXPECT_STREQ(fm1[ln++].c_str(), "  fpos_t rOffset;");
        EXPECT_STREQ(fm1[ln++].c_str(), "		/* HAL : fonction modifiée pour Linux : fpos_t est un entier sous AIX, une structure sous Linux	*/");
        EXPECT_STREQ(fm1[ln++].c_str(), "		/* fpos64_t a été remplacé par fpos_t, et fgetpos64 a été remplacé par fgetpos			*/");
        EXPECT_STREQ(fm1[ln++].c_str(), "");
        EXPECT_STREQ(fm1[ln++].c_str(), "  if (NULL != GIVfDescFicMCD)");
        EXPECT_STREQ(fm1[ln++].c_str(), "  {");
        EXPECT_STREQ(fm1[ln++].c_str(), "    iCodRet = (int4)fgetpos(GIVfDescFicMCD, &rOffset);");
        EXPECT_STREQ(fm1[ln++].c_str(), "    if ((int4)GWCCodeOK != iCodRet)");
        EXPECT_STREQ(fm1[ln++].c_str(), "    {");
        EXPECT_STREQ(fm1[ln++].c_str(), "      GWTTrace (GWT_NIV_FONCT,");
        EXPECT_STREQ(fm1[ln++].c_str(), "                (\"Erreur offset reprise  %d\\n\",iCodRet));");
        EXPECT_STREQ(fm1[ln++].c_str(), "    }");
        EXPECT_STREQ(fm1[ln++].c_str(), "  }");
        EXPECT_STREQ(fm1[ln++].c_str(), "  else");
        EXPECT_STREQ(fm1[ln++].c_str(), "  {");
        EXPECT_STREQ(fm1[ln++].c_str(), "    rOffset.__pos = 0;");
        EXPECT_STREQ(fm1[ln++].c_str(), "    GWTTrace (GWT_NIV_FONCT,");
        EXPECT_STREQ(fm1[ln++].c_str(), "              (\"Erreur offset reprise \\n\"));");
        EXPECT_STREQ(fm1[ln++].c_str(), "  }");
        EXPECT_STREQ(fm1[ln++].c_str(), "");
        EXPECT_STREQ(fm1[ln++].c_str(), "  GWTTrace (GWT_NIV_FONCT,");
        EXPECT_STREQ(fm1[ln++].c_str(), "            (\"Offset reprise  %10.0f\\n\",(double)rOffset.__pos));");
        EXPECT_STREQ(fm1[ln++].c_str(), "");
        EXPECT_STREQ(fm1[ln++].c_str(), "  return(iCodRet);");
        EXPECT_STREQ(fm1[ln++].c_str(), "}");
        EXPECT_STREQ(fm1[ln++].c_str(), "");
        EXPECT_STREQ(fm1[ln++].c_str(), "");
        EXPECT_THROW(fm1[ln].c_str(), std::out_of_range);
        
        fm1.close();
        fm1.reset_line_number_mapping();

        FileManipulator fm2(EMPTYFILE1_FILENAME);
        EXPECT_TRUE(fm2.is_open());
        fm2.create_line_number_mapping();
        EXPECT_EQ(fm2.get_number_of_lines(),
                  FileManipulator_constructor_tests_1::EMPTYFILE1_LINENUM);
        EXPECT_THROW(fm2[1].c_str(), std::out_of_range);
        fm2.close();
        fm2.reset_line_number_mapping();

        FileManipulator fm3(BIGFILE1_FILENAME);
        EXPECT_TRUE(fm3.is_open());
        fm3.create_line_number_mapping();
        EXPECT_EQ(fm3.get_number_of_lines(),
                  FileManipulator_constructor_tests_1::BIGFILE1_LINENUM);
        EXPECT_STREQ(fm3[1].c_str(), "");
        EXPECT_STREQ(fm3[2].c_str(), "");
        EXPECT_STREQ(fm3[3].c_str(), "/*-------------------------------Identification-------------------------------*/");
        EXPECT_STREQ(fm3[54].c_str(), "#include \"GYBinterface_SGBDR.h\"");
        EXPECT_STREQ(fm3[242].c_str(), "union select a.epjobj,a.tpdsob,a.stobj,a.numobj,(TO_CHAR (datact,'FXYYYYMMDD')) from GYTTabEpjMic a, GYTtabProduitGPPParut b  \\");
        EXPECT_STREQ(fm3[30480].c_str(), "  return(iCodRet);");
        EXPECT_STREQ(fm3[30482].c_str(), "}");
        fm3.close();
        fm3.reset_line_number_mapping();
      }

      TEST_F(FileManipulator_constructor_tests_1, EmptyLineMapping)
      {
        FileManipulator fm2(EMPTYFILE1_FILENAME);
        EXPECT_TRUE(fm2.is_open());
        fm2.create_line_number_mapping();
        EXPECT_EQ(fm2.get_number_of_lines(),
                  FileManipulator_constructor_tests_1::EMPTYFILE1_LINENUM);
        EXPECT_THROW(fm2[1].c_str(), std::out_of_range);
        fm2.close();
        fm2.reset_line_number_mapping();
      }
      
      TEST_F(FileManipulator_constructor_tests_1, ReplaceInLine)
      {
        FileManipulator fm3(BIGFILE1_FILENAME);
        EXPECT_TRUE(fm3.is_open());
        fm3.create_line_number_mapping();
        EXPECT_EQ(fm3.get_number_of_lines(),
                  FileManipulator_constructor_tests_1::BIGFILE1_LINENUM);
        EXPECT_STREQ(fm3[1].c_str(), "");
        EXPECT_STREQ(fm3[2].c_str(), "");
        EXPECT_STREQ(fm3[3].c_str(), "/*-------------------------------Identification-------------------------------*/");
        EXPECT_STREQ(fm3[54].c_str(), "#include \"GYBinterface_SGBDR.h\"");
        EXPECT_STREQ(fm3[242].c_str(), "union select a.epjobj,a.tpdsob,a.stobj,a.numobj,(TO_CHAR (datact,'FXYYYYMMDD')) from GYTTabEpjMic a, GYTtabProduitGPPParut b  \\");
        EXPECT_STREQ(fm3[30480].c_str(), "  return(iCodRet);");
        EXPECT_STREQ(fm3[30482].c_str(), "}");

        fm3[3] = "";
        fm3[242] = "union";
        
        EXPECT_STREQ(fm3[3].c_str(), "");
        EXPECT_STREQ(fm3[242].c_str(), "union");
        EXPECT_EQ(fm3.get_number_of_lines(),
                  FileManipulator_constructor_tests_1::BIGFILE1_LINENUM);
        
        fm3.close();
        fm3.reset_line_number_mapping();
      }
      
      TEST_F(FileManipulator_constructor_tests_1, SetLine)
      {
        FileManipulator fm3(BIGFILE1_FILENAME);
        EXPECT_TRUE(fm3.is_open());
        fm3.create_line_number_mapping();
        EXPECT_EQ(fm3.get_number_of_lines(),
                  FileManipulator_constructor_tests_1::BIGFILE1_LINENUM);
        EXPECT_STREQ(fm3[1].c_str(), "");
        EXPECT_STREQ(fm3[2].c_str(), "");
        EXPECT_STREQ(fm3[3].c_str(), "/*-------------------------------Identification-------------------------------*/");
        EXPECT_STREQ(fm3[54].c_str(), "#include \"GYBinterface_SGBDR.h\"");
        EXPECT_STREQ(fm3[242].c_str(), "union select a.epjobj,a.tpdsob,a.stobj,a.numobj,(TO_CHAR (datact,'FXYYYYMMDD')) from GYTTabEpjMic a, GYTtabProduitGPPParut b  \\");
        EXPECT_STREQ(fm3[30480].c_str(), "  return(iCodRet);");
        EXPECT_STREQ(fm3[30482].c_str(), "}");

        fm3.set_line(3, "");
        fm3.set_line(242, "union");
        
        EXPECT_STREQ(fm3[3].c_str(), "");
        EXPECT_STREQ(fm3[242].c_str(), "union");
        EXPECT_EQ(fm3.get_number_of_lines(),
                  FileManipulator_constructor_tests_1::BIGFILE1_LINENUM);
        
        fm3.close();
        fm3.reset_line_number_mapping();
      }
      
    } // ! tests
  } // ! filemanipulator
} // ! jayacode
