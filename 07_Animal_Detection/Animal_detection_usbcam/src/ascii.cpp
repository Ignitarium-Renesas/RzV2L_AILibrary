/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No
* other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM
* EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES
* SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS
* SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of
* this software. By using this software, you agree to the additional terms and conditions found by accessing the
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2022 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : ascii.cpp
* Version      : 7.20
* Description  : RZ/V2L DRP-AI Sample Application for Darknet-PyTorch YOLOv3 MIPI Camera version
***********************************************************************************************************************/

/*****************************************
* Includes
******************************************/
/* ASCII header */
#include "ascii.h"

/*******************************************************************************
* Global Tables
*******************************************************************************/
const char g_ascii_table[][6] =
{
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},      /* ' '*/
  { 0x00, 0x00, 0x79, 0x00, 0x00, 0x00},      /* ! */
  { 0x00, 0x70, 0x00, 0x70, 0x00, 0x00},      /* " */
  { 0x22, 0x7F, 0x22, 0x7F, 0x22, 0x00},      /* # */
  { 0x12, 0x2A, 0x7F, 0x2A, 0x24, 0x00},      /* $ */
  { 0x62, 0x64, 0x08, 0x13, 0x23, 0x00},      /* % */
  { 0x36, 0x49, 0x55, 0x22, 0x05, 0x00},      /* & */
  { 0x00, 0x00, 0x60, 0x00, 0x00, 0x00},      /* ' */
  { 0x00, 0x1C, 0x22, 0x41, 0x00, 0x00},      /* ( */
  { 0x00, 0x41, 0x22, 0x1C, 0x00, 0x00},      /* ) */
  { 0x24, 0x18, 0x7E, 0x18, 0x24, 0x00},      /* * */
  { 0x08, 0x08, 0x3E, 0x08, 0x08, 0x00},      /* + */
  { 0x00, 0x05, 0x06, 0x00, 0x00, 0x00},      /* , */
  { 0x08, 0x08, 0x08, 0x08, 0x08, 0x00},      /* - */
  { 0x00, 0x03, 0x03, 0x00, 0x00, 0x00},      /* . */
  { 0x02, 0x04, 0x08, 0x10, 0x20, 0x00},      /* / */
  { 0x3E, 0x45, 0x49, 0x51, 0x3E, 0x00},      /* 0 */
  { 0x00, 0x21, 0x7F, 0x01, 0x00, 0x00},      /* 1 */
  { 0x21, 0x43, 0x45, 0x49, 0x71, 0x00},      /* 2 */
  { 0x42, 0x41, 0x51, 0x69, 0x46, 0x00},      /* 3 */
  { 0x0C, 0x14, 0x24, 0x7F, 0x04, 0x00},      /* 4 */
  { 0x72, 0x51, 0x51, 0x51, 0x4E, 0x00},      /* 5 */
  { 0x1E, 0x29, 0x49, 0x49, 0x06, 0x00},      /* 6 */
  { 0x40, 0x47, 0x48, 0x50, 0x60, 0x00},      /* 7 */
  { 0x36, 0x49, 0x49, 0x49, 0x36, 0x00},      /* 8 */
  { 0x30, 0x49, 0x49, 0x4A, 0x3C, 0x00},      /* 9 */
  { 0x00, 0x66, 0x66, 0x00, 0x00, 0x00},      /* : */
  { 0x00, 0x35, 0x36, 0x00, 0x00, 0x00},      /* ; */
  { 0x08, 0x14, 0x22, 0x41, 0x00, 0x00},      /* < */
  { 0x14, 0x14, 0x14, 0x14, 0x14, 0x00},      /* = */
  { 0x00, 0x41, 0x22, 0x14, 0x08, 0x00},      /* > */
  { 0x20, 0x40, 0x45, 0x48, 0x30, 0x00},      /* ? */
  { 0x38, 0x45, 0x5D, 0x59, 0x3E, 0x00},      /* @ */
  { 0x1F, 0x24, 0x44, 0x24, 0x1F, 0x00},      /* A */
  { 0x7F, 0x49, 0x49, 0x49, 0x36, 0x00},      /* B */
  { 0x3E, 0x41, 0x41, 0x41, 0x22, 0x00},      /* C */
  { 0x7F, 0x41, 0x41, 0x22, 0x1C, 0x00},      /* D */
  { 0x7F, 0x49, 0x49, 0x49, 0x41, 0x00},      /* E */
  { 0x7F, 0x48, 0x48, 0x48, 0x40, 0x00},      /* F */
  { 0x3E, 0x41, 0x49, 0x49, 0x2F, 0x00},      /* G */
  { 0x7F, 0x08, 0x08, 0x08, 0x7F, 0x00},      /* H */
  { 0x00, 0x41, 0x7F, 0x41, 0x00, 0x00},      /* I */
  { 0x02, 0x01, 0x41, 0x7E, 0x40, 0x00},      /* J */
  { 0x7F, 0x08, 0x14, 0x22, 0x41, 0x00},      /* K */
  { 0x7F, 0x01, 0x01, 0x01, 0x01, 0x00},      /* L */
  { 0x7F, 0x20, 0x18, 0x20, 0x7F, 0x00},      /* M */
  { 0x7F, 0x10, 0x08, 0x04, 0x7F, 0x00},      /* N */
  { 0x3E, 0x41, 0x41, 0x41, 0x3E, 0x00},      /* O */
  { 0x7F, 0x48, 0x48, 0x48, 0x30, 0x00},      /* P */
  { 0x3E, 0x41, 0x45, 0x42, 0x3D, 0x00},      /* Q */
  { 0x7F, 0x48, 0x4C, 0x4A, 0x31, 0x00},      /* R */
  { 0x32, 0x49, 0x49, 0x49, 0x26, 0x00},      /* S */
  { 0x40, 0x40, 0x7F, 0x40, 0x40, 0x00},      /* T */
  { 0x7E, 0x01, 0x01, 0x01, 0x7E, 0x00},      /* U */
  { 0x7C, 0x02, 0x01, 0x02, 0x7C, 0x00},      /* V */
  { 0x7E, 0x01, 0x0E, 0x01, 0x7E, 0x00},      /* W */
  { 0x63, 0x14, 0x08, 0x14, 0x63, 0x00},      /* X */
  { 0x70, 0x08, 0x07, 0x08, 0x70, 0x00},      /* Y */
  { 0x43, 0x45, 0x49, 0x51, 0x61, 0x00},      /* Z */
  { 0x00, 0x7F, 0x41, 0x00, 0x00, 0x00},      /* [ */
  { 0x20, 0x10, 0x08, 0x04, 0x02, 0x00},      /* "\" */
  { 0x00, 0x00, 0x41, 0x7F, 0x00, 0x00},      /* ] */
  { 0x00, 0x20, 0x40, 0x20, 0x00, 0x00},      /* ^ */
  { 0x01, 0x01, 0x01, 0x01, 0x01, 0x00},      /* _ */
  { 0x00, 0x40, 0x20, 0x00, 0x00, 0x00},      /* ' */
  { 0x02, 0x15, 0x15, 0x0F, 0x01, 0x00},      /* a */
  { 0x00, 0x7F, 0x11, 0x11, 0x0E, 0x00},      /* b */
  { 0x00, 0x0E, 0x11, 0x11, 0x11, 0x00},      /* c */
  { 0x0E, 0x11, 0x11, 0x7F, 0x00, 0x00},      /* d */
  { 0x0E, 0x15, 0x15, 0x15, 0x0C, 0x00},      /* e */
  { 0x00, 0x10, 0x3F, 0x50, 0x50, 0x00},      /* f */
  { 0x08, 0x15, 0x15, 0x15, 0x1E, 0x00},      /* g */
  { 0x00, 0x7F, 0x10, 0x10, 0x0F, 0x00},      /* h */
  { 0x00, 0x11, 0x5F, 0x01, 0x00, 0x00},      /* i */
  { 0x02, 0x01, 0x01, 0x5E, 0x00, 0x00},      /* j */
  { 0x00, 0x7F, 0x04, 0x0A, 0x11, 0x00},      /* k */
  { 0x00, 0x41, 0x7F, 0x01, 0x00, 0x00},      /* l */
  { 0x1F, 0x10, 0x0F, 0x10, 0x0F, 0x00},      /* m */
  { 0x00, 0x1F, 0x10, 0x10, 0x0F, 0x00},      /* n */
  { 0x0E, 0x11, 0x11, 0x11, 0x0E, 0x00},      /* 0 */
  { 0x1F, 0x14, 0x14, 0x14, 0x08, 0x00},      /* p */
  { 0x08, 0x14, 0x14, 0x14, 0x1F, 0x00},      /* q */
  { 0x00, 0x1F, 0x08, 0x10, 0x10, 0x00},      /* r */
  { 0x09, 0x15, 0x15, 0x15, 0x12, 0x00},      /* s */
  { 0x00, 0x10, 0x7E, 0x11, 0x01, 0x00},      /* t */
  { 0x00, 0x1E, 0x01, 0x01, 0x1F, 0x00},      /* u */
  { 0x1C, 0x02, 0x01, 0x02, 0x1C, 0x00},      /* v */
  { 0x1E, 0x01, 0x06, 0x01, 0x1E, 0x00},      /* w */
  { 0x11, 0x0A, 0x04, 0x0A, 0x11, 0x00},      /* x */
  { 0x18, 0x05, 0x05, 0x1E, 0x00, 0x00},      /* y */
  { 0x11, 0x13, 0x15, 0x19, 0x11, 0x00},      /* z */
  { 0x00, 0x08, 0x36, 0x41, 0x00, 0x00},      /* { */
  { 0x00, 0x00, 0x7F, 0x00, 0x00, 0x00},      /* | */
  { 0x00, 0x41, 0x36, 0x08, 0x00, 0x00},      /* } */
  { 0x00, 0x20, 0x40, 0x20, 0x40, 0x00}       /* ~ */
  };
