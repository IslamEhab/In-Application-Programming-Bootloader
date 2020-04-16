#ifndef _BIT_MATH_H
#define _BIT_MATH_H

#define CLR_PORT(VAR)             (VAR) &= ~(0x11111111)
#define SET_PORT(VAR,VALUE,BITNO) (VAR) |=  (VALUE << (BITNO))
#define SET_BIT(VAR,BITNO)        (VAR) |=  (1 << (BITNO))
#define CLR_BIT(VAR,BITNO)        (VAR) &= ~(1 << (BITNO))
#define TOG_BIT(VAR,BITNO)        (VAR) ^=  (1 << (BITNO))
#define GET_BIT(VAR,BITNO)        (((VAR) >> (BITNO)) & 0x01)


#endif
