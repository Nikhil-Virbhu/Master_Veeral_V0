/*
 * Master_Monitor_Parameter.h
 *
 *  Created on: Nov 29, 2023
 *      Author: ujwalpatel
 */

#ifndef INC_MASTER_MONITOR_PARAMETER_H_
#define INC_MASTER_MONITOR_PARAMETER_H_

#include "main.h"

typedef union
{
  struct
  {
    uint16_t rsvd0 : 1;        //bit 0
    uint16_t rsvd1 : 1;        //bit 1
    uint16_t rsvd2 : 1;        //bit 2
    uint16_t rsvd3 : 1;        //bit 3
    uint16_t rsvd4 : 1;       //bit 4
    uint16_t rsvd5 : 1;       //bit 5
    uint16_t rsvd6 : 1;       //bit 6
    uint16_t rsvd7 : 1;       //bit 7
    uint16_t rsvd8 : 1;        //bit 8
    uint16_t rsvd9 : 1;        //bit 9
    uint16_t rsvd10: 1;        //bit 10
    uint16_t rsvd11: 1;        //bit 11
    uint16_t rsvd12: 1;       //bit 12
    uint16_t rsvd13: 1;       //bit 13
    uint16_t rsvd14: 1;       //bit 14
    uint16_t rsvd15: 1;       //bit 15
  }bits;
  uint16_t byte;
}mfault1_t;

typedef union
{
  struct
  {
    uint16_t rsvd0 : 1;        //bit 0
    uint16_t rsvd1 : 1;        //bit 1
    uint16_t rsvd2 : 1;        //bit 2
    uint16_t rsvd3 : 1;        //bit 3
    uint16_t rsvd4 : 1;       //bit 4
    uint16_t rsvd5 : 1;       //bit 5
    uint16_t rsvd6 : 1;       //bit 6
    uint16_t rsvd7 : 1;       //bit 7
    uint16_t rsvd8 : 1;        //bit 8
    uint16_t rsvd9 : 1;        //bit 9
    uint16_t rsvd10: 1;        //bit 10
    uint16_t rsvd11: 1;        //bit 11
    uint16_t rsvd12: 1;       //bit 12
    uint16_t rsvd13: 1;       //bit 13
    uint16_t rsvd14: 1;       //bit 14
    uint16_t rsvd15: 1;       //bit 15
  }bits;
  uint16_t byte;
}mfault2_t;

typedef union
{
  struct
  {
    uint16_t rsvd0 : 1;        //bit 0
    uint16_t rsvd1 : 1;        //bit 1
    uint16_t rsvd2 : 1;        //bit 2
    uint16_t rsvd3 : 1;        //bit 3
    uint16_t rsvd4 : 1;       //bit 4
    uint16_t rsvd5 : 1;       //bit 5
    uint16_t rsvd6 : 1;       //bit 6
    uint16_t rsvd7 : 1;       //bit 7
    uint16_t rsvd8 : 1;        //bit 8
    uint16_t rsvd9 : 1;        //bit 9
    uint16_t rsvd10: 1;        //bit 10
    uint16_t rsvd11: 1;        //bit 11
    uint16_t rsvd12: 1;       //bit 12
    uint16_t rsvd13: 1;       //bit 13
    uint16_t rsvd14: 1;       //bit 14
    uint16_t rsvd15: 1;       //bit 15
  }bits;
  uint16_t byte;
}mfault3_t;

typedef union
{
  struct
  {
    uint16_t rsvd0 : 1;        //bit 0
    uint16_t rsvd1 : 1;        //bit 1
    uint16_t rsvd2 : 1;        //bit 2
    uint16_t rsvd3 : 1;        //bit 3
    uint16_t rsvd4 : 1;       //bit 4
    uint16_t rsvd5 : 1;       //bit 5
    uint16_t rsvd6 : 1;       //bit 6
    uint16_t rsvd7 : 1;       //bit 7
    uint16_t rsvd8 : 1;        //bit 8
    uint16_t rsvd9 : 1;        //bit 9
    uint16_t rsvd10: 1;        //bit 10
    uint16_t rsvd11: 1;        //bit 11
    uint16_t rsvd12: 1;       //bit 12
    uint16_t rsvd13: 1;       //bit 13
    uint16_t rsvd14: 1;       //bit 14
    uint16_t rsvd15: 1;       //bit 15
  }bits;
  uint16_t byte;
}mfault4_t;

typedef union
{
  struct
  {
    uint16_t rsvd0 : 1;        //bit 0
    uint16_t rsvd1 : 1;        //bit 1
    uint16_t rsvd2 : 1;        //bit 2
    uint16_t rsvd3 : 1;        //bit 3
    uint16_t rsvd4 : 1;       //bit 4
    uint16_t rsvd5 : 1;       //bit 5
    uint16_t rsvd6 : 1;       //bit 6
    uint16_t rsvd7 : 1;       //bit 7
    uint16_t rsvd8 : 1;        //bit 8
    uint16_t rsvd9 : 1;        //bit 9
    uint16_t rsvd10: 1;        //bit 10
    uint16_t rsvd11: 1;        //bit 11
    uint16_t rsvd12: 1;       //bit 12
    uint16_t rsvd13: 1;       //bit 13
    uint16_t rsvd14: 1;       //bit 14
    uint16_t rsvd15: 1;       //bit 15
  }bits;
  uint16_t byte;
}mfault5_t;

typedef union
{
  struct
  {
    uint16_t rsvd0 : 1;        //bit 0
    uint16_t rsvd1 : 1;        //bit 1
    uint16_t rsvd2 : 1;        //bit 2
    uint16_t rsvd3 : 1;        //bit 3
    uint16_t rsvd4 : 1;       //bit 4
    uint16_t rsvd5 : 1;       //bit 5
    uint16_t rsvd6 : 1;       //bit 6
    uint16_t rsvd7 : 1;       //bit 7
    uint16_t rsvd8 : 1;        //bit 8
    uint16_t rsvd9 : 1;        //bit 9
    uint16_t rsvd10: 1;        //bit 10
    uint16_t rsvd11: 1;        //bit 11
    uint16_t rsvd12: 1;       //bit 12
    uint16_t rsvd13: 1;       //bit 13
    uint16_t rsvd14: 1;       //bit 14
    uint16_t rsvd15: 1;       //bit 15
  }bits;
  uint16_t byte;
}mfault6_t;

typedef union
{
  struct
  {
    uint16_t rsvd0 : 1;        //bit 0
    uint16_t rsvd1 : 1;        //bit 1
    uint16_t rsvd2 : 1;        //bit 2
    uint16_t rsvd3 : 1;        //bit 3
    uint16_t rsvd4 : 1;       //bit 4
    uint16_t rsvd5 : 1;       //bit 5
    uint16_t rsvd6 : 1;       //bit 6
    uint16_t rsvd7 : 1;       //bit 7
    uint16_t rsvd8 : 1;        //bit 8
    uint16_t rsvd9 : 1;        //bit 9
    uint16_t rsvd10: 1;        //bit 10
    uint16_t rsvd11: 1;        //bit 11
    uint16_t rsvd12: 1;       //bit 12
    uint16_t rsvd13: 1;       //bit 13
    uint16_t rsvd14: 1;       //bit 14
    uint16_t rsvd15: 1;       //bit 15
  }bits;
  uint16_t byte;
}mfault7_t;

typedef union
{
  struct
  {
    uint16_t rsvd0 : 1;        //bit 0
    uint16_t rsvd1 : 1;        //bit 1
    uint16_t rsvd2 : 1;        //bit 2
    uint16_t rsvd3 : 1;        //bit 3
    uint16_t rsvd4 : 1;       //bit 4
    uint16_t rsvd5 : 1;       //bit 5
    uint16_t rsvd6 : 1;       //bit 6
    uint16_t rsvd7 : 1;       //bit 7
    uint16_t rsvd8 : 1;        //bit 8
    uint16_t rsvd9 : 1;        //bit 9
    uint16_t rsvd10: 1;        //bit 10
    uint16_t rsvd11: 1;        //bit 11
    uint16_t rsvd12: 1;       //bit 12
    uint16_t rsvd13: 1;       //bit 13
    uint16_t rsvd14: 1;       //bit 14
    uint16_t rsvd15: 1;       //bit 15
  }bits;
  uint16_t byte;
}mfault8_t;

typedef union
{
  struct
  {
    uint16_t rsvd0 : 1;        //bit 0
    uint16_t rsvd1 : 1;        //bit 1
    uint16_t rsvd2 : 1;        //bit 2
    uint16_t rsvd3 : 1;        //bit 3
    uint16_t rsvd4 : 1;       //bit 4
    uint16_t rsvd5 : 1;       //bit 5
    uint16_t rsvd6 : 1;       //bit 6
    uint16_t rsvd7 : 1;       //bit 7
    uint16_t rsvd8 : 1;        //bit 8
    uint16_t rsvd9 : 1;        //bit 9
    uint16_t rsvd10: 1;        //bit 10
    uint16_t rsvd11: 1;        //bit 11
    uint16_t rsvd12: 1;       //bit 12
    uint16_t rsvd13: 1;       //bit 13
    uint16_t rsvd14: 1;       //bit 14
    uint16_t rsvd15: 1;       //bit 15
  }bits;
  uint16_t byte;
}mfault9_t;

typedef union
{
  struct
  {
    uint16_t rsvd0 : 1;        //bit 0
    uint16_t rsvd1 : 1;        //bit 1
    uint16_t rsvd2 : 1;        //bit 2
    uint16_t rsvd3 : 1;        //bit 3
    uint16_t rsvd4 : 1;       //bit 4
    uint16_t rsvd5 : 1;       //bit 5
    uint16_t rsvd6 : 1;       //bit 6
    uint16_t rsvd7 : 1;       //bit 7
    uint16_t rsvd8 : 1;        //bit 8
    uint16_t rsvd9 : 1;        //bit 9
    uint16_t rsvd10: 1;        //bit 10
    uint16_t rsvd11: 1;        //bit 11
    uint16_t rsvd12: 1;       //bit 12
    uint16_t rsvd13: 1;       //bit 13
    uint16_t rsvd14: 1;       //bit 14
    uint16_t rsvd15: 1;       //bit 15
  }bits;
  uint16_t byte;
}mfault10_t;

typedef union
{
  struct
  {
    uint16_t rsvd0 : 1;        //bit 0
    uint16_t rsvd1 : 1;        //bit 1
    uint16_t rsvd2 : 1;        //bit 2
    uint16_t rsvd3 : 1;        //bit 3
    uint16_t rsvd4 : 1;       //bit 4
    uint16_t rsvd5 : 1;       //bit 5
    uint16_t rsvd6 : 1;       //bit 6
    uint16_t rsvd7 : 1;       //bit 7
    uint16_t rsvd8 : 1;        //bit 8
    uint16_t rsvd9 : 1;        //bit 9
    uint16_t rsvd10: 1;        //bit 10
    uint16_t rsvd11: 1;        //bit 11
    uint16_t rsvd12: 1;       //bit 12
    uint16_t rsvd13: 1;       //bit 13
    uint16_t rsvd14: 1;       //bit 14
    uint16_t rsvd15: 1;       //bit 15
  }bits;
  uint16_t byte;
}mstatus1__t;

typedef union
{
  struct
  {
    uint16_t rsvd0 : 1;        //bit 0
    uint16_t rsvd1 : 1;        //bit 1
    uint16_t rsvd2 : 1;        //bit 2
    uint16_t rsvd3 : 1;        //bit 3
    uint16_t rsvd4 : 1;       //bit 4
    uint16_t rsvd5 : 1;       //bit 5
    uint16_t rsvd6 : 1;       //bit 6
    uint16_t rsvd7 : 1;       //bit 7
    uint16_t rsvd8 : 1;        //bit 8
    uint16_t rsvd9 : 1;        //bit 9
    uint16_t rsvd10: 1;        //bit 10
    uint16_t rsvd11: 1;        //bit 11
    uint16_t rsvd12: 1;       //bit 12
    uint16_t rsvd13: 1;       //bit 13
    uint16_t rsvd14: 1;       //bit 14
    uint16_t rsvd15: 1;       //bit 15
  }bits;
  uint16_t byte;
}mstatus2_t;

typedef union
{
  struct
  {
    uint16_t rsvd0 : 1;        //bit 0
    uint16_t rsvd1 : 1;        //bit 1
    uint16_t rsvd2 : 1;        //bit 2
    uint16_t rsvd3 : 1;        //bit 3
    uint16_t rsvd4 : 1;       //bit 4
    uint16_t rsvd5 : 1;       //bit 5
    uint16_t rsvd6 : 1;       //bit 6
    uint16_t rsvd7 : 1;       //bit 7
    uint16_t rsvd8 : 1;        //bit 8
    uint16_t rsvd9 : 1;        //bit 9
    uint16_t rsvd10: 1;        //bit 10
    uint16_t rsvd11: 1;        //bit 11
    uint16_t rsvd12: 1;       //bit 12
    uint16_t rsvd13: 1;       //bit 13
    uint16_t rsvd14: 1;       //bit 14
    uint16_t rsvd15: 1;       //bit 15
  }bits;
  uint16_t byte;
}mstatus3_t;

typedef union
{
  struct
  {
    uint16_t rsvd0 : 1;        //bit 0
    uint16_t rsvd1 : 1;        //bit 1
    uint16_t rsvd2 : 1;        //bit 2
    uint16_t rsvd3 : 1;        //bit 3
    uint16_t rsvd4 : 1;       //bit 4
    uint16_t rsvd5 : 1;       //bit 5
    uint16_t rsvd6 : 1;       //bit 6
    uint16_t rsvd7 : 1;       //bit 7
    uint16_t rsvd8 : 1;        //bit 8
    uint16_t rsvd9 : 1;        //bit 9
    uint16_t rsvd10: 1;        //bit 10
    uint16_t rsvd11: 1;        //bit 11
    uint16_t rsvd12: 1;       //bit 12
    uint16_t rsvd13: 1;       //bit 13
    uint16_t rsvd14: 1;       //bit 14
    uint16_t rsvd15: 1;       //bit 15
  }bits;
  uint16_t byte;
}mstatus4_t;

typedef union
{
  struct
  {
    uint16_t rsvd0 : 1;        //bit 0
    uint16_t rsvd1 : 1;        //bit 1
    uint16_t rsvd2 : 1;        //bit 2
    uint16_t rsvd3 : 1;        //bit 3
    uint16_t rsvd4 : 1;       //bit 4
    uint16_t rsvd5 : 1;       //bit 5
    uint16_t rsvd6 : 1;       //bit 6
    uint16_t rsvd7 : 1;       //bit 7
    uint16_t rsvd8 : 1;        //bit 8
    uint16_t rsvd9 : 1;        //bit 9
    uint16_t rsvd10: 1;        //bit 10
    uint16_t rsvd11: 1;        //bit 11
    uint16_t rsvd12: 1;       //bit 12
    uint16_t rsvd13: 1;       //bit 13
    uint16_t rsvd14: 1;       //bit 14
    uint16_t rsvd15: 1;       //bit 15
  }bits;
  uint16_t byte;
}mstatus5_t;

typedef union
{
  struct
  {
    uint16_t rsvd0 : 1;        //bit 0
    uint16_t rsvd1 : 1;        //bit 1
    uint16_t rsvd2 : 1;        //bit 2
    uint16_t rsvd3 : 1;        //bit 3
    uint16_t rsvd4 : 1;       //bit 4
    uint16_t rsvd5 : 1;       //bit 5
    uint16_t rsvd6 : 1;       //bit 6
    uint16_t rsvd7 : 1;       //bit 7
    uint16_t rsvd8 : 1;        //bit 8
    uint16_t rsvd9 : 1;        //bit 9
    uint16_t rsvd10: 1;        //bit 10
    uint16_t rsvd11: 1;        //bit 11
    uint16_t rsvd12: 1;       //bit 12
    uint16_t rsvd13: 1;       //bit 13
    uint16_t rsvd14: 1;       //bit 14
    uint16_t rsvd15: 1;       //bit 15
  }bits;
  uint16_t byte;
}mstatus6_t;

typedef union
{
  struct
  {
    uint16_t rsvd0 : 1;        //bit 0
    uint16_t rsvd1 : 1;        //bit 1
    uint16_t rsvd2 : 1;        //bit 2
    uint16_t rsvd3 : 1;        //bit 3
    uint16_t rsvd4 : 1;       //bit 4
    uint16_t rsvd5 : 1;       //bit 5
    uint16_t rsvd6 : 1;       //bit 6
    uint16_t rsvd7 : 1;       //bit 7
    uint16_t rsvd8 : 1;        //bit 8
    uint16_t rsvd9 : 1;        //bit 9
    uint16_t rsvd10: 1;        //bit 10
    uint16_t rsvd11: 1;        //bit 11
    uint16_t rsvd12: 1;       //bit 12
    uint16_t rsvd13: 1;       //bit 13
    uint16_t rsvd14: 1;       //bit 14
    uint16_t rsvd15: 1;       //bit 15
  }bits;
  uint16_t byte;
}mstatus7_t;

typedef union
{
  struct
  {
    uint16_t rsvd0 : 1;        //bit 0
    uint16_t rsvd1 : 1;        //bit 1
    uint16_t rsvd2 : 1;        //bit 2
    uint16_t rsvd3 : 1;        //bit 3
    uint16_t rsvd4 : 1;       //bit 4
    uint16_t rsvd5 : 1;       //bit 5
    uint16_t rsvd6 : 1;       //bit 6
    uint16_t rsvd7 : 1;       //bit 7
    uint16_t rsvd8 : 1;        //bit 8
    uint16_t rsvd9 : 1;        //bit 9
    uint16_t rsvd10: 1;        //bit 10
    uint16_t rsvd11: 1;        //bit 11
    uint16_t rsvd12: 1;       //bit 12
    uint16_t rsvd13: 1;       //bit 13
    uint16_t rsvd14: 1;       //bit 14
    uint16_t rsvd15: 1;       //bit 15
  }bits;
  uint16_t byte;
}mstatus8_t;

typedef union
{
  struct
  {
    uint16_t rsvd0 : 1;        //bit 0
    uint16_t rsvd1 : 1;        //bit 1
    uint16_t rsvd2 : 1;        //bit 2
    uint16_t rsvd3 : 1;        //bit 3
    uint16_t rsvd4 : 1;       //bit 4
    uint16_t rsvd5 : 1;       //bit 5
    uint16_t rsvd6 : 1;       //bit 6
    uint16_t rsvd7 : 1;       //bit 7
    uint16_t rsvd8 : 1;        //bit 8
    uint16_t rsvd9 : 1;        //bit 9
    uint16_t rsvd10: 1;        //bit 10
    uint16_t rsvd11: 1;        //bit 11
    uint16_t rsvd12: 1;       //bit 12
    uint16_t rsvd13: 1;       //bit 13
    uint16_t rsvd14: 1;       //bit 14
    uint16_t rsvd15: 1;       //bit 15
  }bits;
  uint16_t byte;
}mstatus9_t;

typedef union
{
  struct
  {
    uint16_t rsvd0 : 1;        //bit 0
    uint16_t rsvd1 : 1;        //bit 1
    uint16_t rsvd2 : 1;        //bit 2
    uint16_t rsvd3 : 1;        //bit 3
    uint16_t rsvd4 : 1;       //bit 4
    uint16_t rsvd5 : 1;       //bit 5
    uint16_t rsvd6 : 1;       //bit 6
    uint16_t rsvd7 : 1;       //bit 7
    uint16_t rsvd8 : 1;        //bit 8
    uint16_t rsvd9 : 1;        //bit 9
    uint16_t rsvd10: 1;        //bit 10
    uint16_t rsvd11: 1;        //bit 11
    uint16_t rsvd12: 1;       //bit 12
    uint16_t rsvd13: 1;       //bit 13
    uint16_t rsvd14: 1;       //bit 14
    uint16_t rsvd15: 1;       //bit 15
  }bits;
  uint16_t byte;
}mstatus10_t;

typedef union
{
  struct
  {
    uint16_t rsvd0 : 1;        //bit 0
    uint16_t rsvd1 : 1;        //bit 1
    uint16_t rsvd2 : 1;        //bit 2
    uint16_t rsvd3 : 1;        //bit 3
    uint16_t rsvd4 : 1;       //bit 4
    uint16_t rsvd5 : 1;       //bit 5
    uint16_t rsvd6 : 1;       //bit 6
    uint16_t rsvd7 : 1;       //bit 7
    uint16_t rsvd8 : 1;        //bit 8
    uint16_t rsvd9 : 1;        //bit 9
    uint16_t rsvd10: 1;        //bit 10
    uint16_t rsvd11: 1;        //bit 11
    uint16_t rsvd12: 1;       //bit 12
    uint16_t rsvd13: 1;       //bit 13
    uint16_t rsvd14: 1;       //bit 14
    uint16_t rsvd15: 1;       //bit 15
  }bits;
  uint16_t byte;
}sfault1_2_t;

typedef union
{
  struct
  {
    uint16_t rsvd0 : 1;        //bit 0
    uint16_t rsvd1 : 1;        //bit 1
    uint16_t rsvd2 : 1;        //bit 2
    uint16_t rsvd3 : 1;        //bit 3
    uint16_t rsvd4 : 1;       //bit 4
    uint16_t rsvd5 : 1;       //bit 5
    uint16_t rsvd6 : 1;       //bit 6
    uint16_t rsvd7 : 1;       //bit 7
    uint16_t rsvd8 : 1;        //bit 8
    uint16_t rsvd9 : 1;        //bit 9
    uint16_t rsvd10: 1;        //bit 10
    uint16_t rsvd11: 1;        //bit 11
    uint16_t rsvd12: 1;       //bit 12
    uint16_t rsvd13: 1;       //bit 13
    uint16_t rsvd14: 1;       //bit 14
    uint16_t rsvd15: 1;       //bit 15
  }bits;
  uint16_t byte;
}sfault3_4_t;

typedef union
{
  struct
  {
    uint16_t rsvd0 : 1;        //bit 0
    uint16_t rsvd1 : 1;        //bit 1
    uint16_t rsvd2 : 1;        //bit 2
    uint16_t rsvd3 : 1;        //bit 3
    uint16_t rsvd4 : 1;       //bit 4
    uint16_t rsvd5 : 1;       //bit 5
    uint16_t rsvd6 : 1;       //bit 6
    uint16_t rsvd7 : 1;       //bit 7
    uint16_t rsvd8 : 1;        //bit 8
    uint16_t rsvd9 : 1;        //bit 9
    uint16_t rsvd10: 1;        //bit 10
    uint16_t rsvd11: 1;        //bit 11
    uint16_t rsvd12: 1;       //bit 12
    uint16_t rsvd13: 1;       //bit 13
    uint16_t rsvd14: 1;       //bit 14
    uint16_t rsvd15: 1;       //bit 15
  }bits;
  uint16_t byte;
}sfault5_6_t;

typedef union
{
  struct
  {
    uint16_t rsvd0 : 1;        //bit 0
    uint16_t rsvd1 : 1;        //bit 1
    uint16_t rsvd2 : 1;        //bit 2
    uint16_t rsvd3 : 1;        //bit 3
    uint16_t rsvd4 : 1;       //bit 4
    uint16_t rsvd5 : 1;       //bit 5
    uint16_t rsvd6 : 1;       //bit 6
    uint16_t rsvd7 : 1;       //bit 7
    uint16_t rsvd8 : 1;        //bit 8
    uint16_t rsvd9 : 1;        //bit 9
    uint16_t rsvd10: 1;        //bit 10
    uint16_t rsvd11: 1;        //bit 11
    uint16_t rsvd12: 1;       //bit 12
    uint16_t rsvd13: 1;       //bit 13
    uint16_t rsvd14: 1;       //bit 14
    uint16_t rsvd15: 1;       //bit 15
  }bits;
  uint16_t byte;
}sfault7_8_t;

typedef union
{
  struct
  {
    uint16_t rsvd0 : 1;        //bit 0
    uint16_t rsvd1 : 1;        //bit 1
    uint16_t rsvd2 : 1;        //bit 2
    uint16_t rsvd3 : 1;        //bit 3
    uint16_t rsvd4 : 1;       //bit 4
    uint16_t rsvd5 : 1;       //bit 5
    uint16_t rsvd6 : 1;       //bit 6
    uint16_t rsvd7 : 1;       //bit 7
    uint16_t rsvd8 : 1;        //bit 8
    uint16_t rsvd9 : 1;        //bit 9
    uint16_t rsvd10: 1;        //bit 10
    uint16_t rsvd11: 1;        //bit 11
    uint16_t rsvd12: 1;       //bit 12
    uint16_t rsvd13: 1;       //bit 13
    uint16_t rsvd14: 1;       //bit 14
    uint16_t rsvd15: 1;       //bit 15
  }bits;
  uint16_t byte;
}sstatus1_2_t;

typedef union
{
  struct
  {
    uint16_t rsvd0 : 1;        //bit 0
    uint16_t rsvd1 : 1;        //bit 1
    uint16_t rsvd2 : 1;        //bit 2
    uint16_t rsvd3 : 1;        //bit 3
    uint16_t rsvd4 : 1;       //bit 4
    uint16_t rsvd5 : 1;       //bit 5
    uint16_t rsvd6 : 1;       //bit 6
    uint16_t rsvd7 : 1;       //bit 7
    uint16_t rsvd8 : 1;        //bit 8
    uint16_t rsvd9 : 1;        //bit 9
    uint16_t rsvd10: 1;        //bit 10
    uint16_t rsvd11: 1;        //bit 11
    uint16_t rsvd12: 1;       //bit 12
    uint16_t rsvd13: 1;       //bit 13
    uint16_t rsvd14: 1;       //bit 14
    uint16_t rsvd15: 1;       //bit 15
  }bits;
  uint16_t byte;
}sstatus3_4_t;

typedef struct
{
	uint16_t diode_temp; 			// slave main parameter 1
	uint16_t trafo_temp;
	uint16_t fec_temp;
	uint16_t psfb_temp;
	uint16_t dc_bus_voltage;
	uint16_t dc_bus_current;
	uint16_t fec_input_current;
	uint16_t psfb_output_voltage;
	uint16_t psfb_output_current;	// slave main parameter 9 --> SLAVE_MAIN_PARAMETER_COUNT = 9
    sfault1_2_t sFault1_2;
    sfault3_4_t sFault3_4;
    sfault5_6_t sFault5_6;
    sfault7_8_t sFault7_8;
    sstatus1_2_t sStatus1_2;
    sstatus3_4_t sStatus3_4;
    uint16_t rsvd0;
    uint16_t rsvd1;
    uint16_t rsvd2;
    uint16_t rsvd3;
    uint16_t rsvd4;
    uint16_t rsvd5;
    uint16_t rsvd6;
    uint16_t rsvd7;
    uint16_t rsvd8;
    uint16_t rsvd9;
    uint16_t rsvd10;
    uint16_t rsvd11;
    uint16_t rsvd12;
    uint16_t rsvd13;
    uint16_t rsvd14;
    uint16_t rsvd15;
    uint16_t rsvd16;
}slave_para;

typedef struct
{
	uint16_t r_phase_volt; 	// master main parameter 1
	uint16_t y_phase_volt;
	uint16_t b_phase_volt;
	uint16_t r_phase_cur;
    uint16_t y_phase_cur;
    uint16_t b_phase_cur;
    uint16_t active_power;
    uint16_t power_factor;
    uint16_t system_freq;
    uint16_t output_voltage;
    uint16_t output_current;
    uint16_t output_power; 	// master main parameter 12 --> MASTER_MAIN_PARAMETER_COUNT =12
    mfault1_t mFault1;
    mfault2_t mFault2;
    mfault3_t mFault3;
    mfault4_t mFault4;
    mfault5_t mFault5;
    mfault6_t mFault6;
    mfault7_t mFault7;
    mfault8_t mFault8;
    mfault9_t mFault9;
    mfault10_t mFault10;
    mstatus1__t mStatus1;
    mstatus2_t mStatus2;
    mstatus3_t mStatus3;
    mstatus4_t mStatus4;
    mstatus5_t mStatus5;
    mstatus6_t mStatus6;
    mstatus7_t mStatus7;
    mstatus8_t mStatus8;
    mstatus9_t mStatus9;
    mstatus10_t mStatus10;
    slave_para  cell[39];
}master_para;

#endif /* INC_MASTER_MONITOR_PARAMETER_H_ */
