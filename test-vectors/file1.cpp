/*-------------------------------Identification-------------------------------*/
/**                           Sardane EasyDoc 02.1                           **/
#ifndef LINT
#define __WATINCLUDE__ "file1.cpp"
#ifdef __TIMESTAMP__
#define WhatStampGIVMiseEnFormeEpj_pc "@(#)SARDANE $Revision:   3.132  $	GIVMiseEnFormeEpj.pc	""("__TIMESTAMP__"-"__DATE__" "__TIME__")"
#endif	/* __TIMESTAMP__ */

/*----------------------------------Includes----------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <memory.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <iconv.h>

/*----Fonction----------------------------------------------------------------*/
/*                                                                            */
/* Fonction  : GIVCodeClient                                                  */
/*----------------------------------------------------------------------------*/
int4 GIVCodeClient ( char *cClient, int4 lg_chp )
{
  int4 iLong = 0;
  int4 iVal,i = 0;
  int4 iCodRet = (int4)GWCCodeOK;
  char client_decode[14+1]="";  /* numlo ou IG decode pr bloc de parution */

  for (i=0;i<lg_chp;i++)
  {
    if ( (cClient[i] >= giv_Min) && (cClient[i] <= giv_Max ))
    {
      strcpy (client_decode, cClient);
      break;
    }
  }

  if (lg_chp == i)
  {
    while (iLong < lg_chp )
    {
      iVal = 0;
      while (((nat1)(cClient[iLong]) != givtcCLIENTLO[iVal]) && (256 != iVal))
      {
        iVal++;
      }
      if ( iVal == 256)
      {
        GWTTrace (GWT_NIV_FONCT,
                  ("Erreur ne retrouve pas la valeur ...\n"));
        iCodRet = (int4)GWCCodeKO ;
      }
      client_decode[(iLong*2)+1] = (char)((iVal % giv_DIV_PAR_DIX) + '0');
      iVal = iVal / giv_DIV_PAR_DIX;
      client_decode[(iLong*2)] = (char)((iVal % giv_DIV_PAR_DIX) + '0');
      iLong++;

    }
  }
  GWTTrace (GWT_NIV_FONCT,
            ( "client_decode = %s\n", client_decode ));
  strcpy ( GIVtcClientDecode,client_decode);

  return(iCodRet);

}
/*---------------------fin fonction-------------------------------------------*/


/*----Fonction----------------------------------------------------------------*/
/*                                                                            */
/* Fonction  : givReprise ()                                                  */
/*                                                                            */
/* But       : offset de reprise                                              */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* Entree(s) :                                                                */
/*                                                                            */
/* Sortie(s) : OK ou KO                                                       */
/*                                                                            */
/* Portable  : Transparent                                                    */
/*                                                                            */
/*----------------------------------------------------------------------------*/

static int4 givReprise (void)
{
  int4 iCodRet = GWCCodeOK;     /* Code retour de la fonction */
  fpos_t rOffset;
		/* HAL : fonction modifiée pour Linux : fpos_t est un entier sous AIX, une structure sous Linux	*/
		/* fpos64_t a été remplacé par fpos_t, et fgetpos64 a été remplacé par fgetpos			*/

  if (NULL != GIVfDescFicMCD)
  {
    iCodRet = (int4)fgetpos(GIVfDescFicMCD, &rOffset);
    if ((int4)GWCCodeOK != iCodRet)
    {
      GWTTrace (GWT_NIV_FONCT,
                ("Erreur offset reprise  %d\n",iCodRet));
    }
  }
  else
  {
    rOffset.__pos = 0;
    GWTTrace (GWT_NIV_FONCT,
              ("Erreur offset reprise \n"));
  }

  GWTTrace (GWT_NIV_FONCT,
            ("Offset reprise  %10.0f\n",(double)rOffset.__pos));

  return(iCodRet);
}


