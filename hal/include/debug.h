/*
 * debug.h
 *
 *  Created on: Jan 13, 2016
 *      Author: lukas
 */

#ifndef DEBUG_H
#define DEBUG_H


//*****************************************************************************
//
// Prototype for the function that is called when an invalid argument is passed
// to an API.  This is only used when doing a DEBUG build.
//
//*****************************************************************************
extern void __error__(char *pcFilename, uint32_t ui32Line);

//*****************************************************************************
//
// The ASSERT macro, which does the actual assertion checking.  Typically, this
// will be for procedure arguments.
//
//*****************************************************************************
#ifdef DEBUG
#define ASSERT(expr) do                                                       \
                     {                                                        \
                         if(!(expr))                                          \
                         {                                                    \
                             __error__(__FILE__, __LINE__);                   \
                         }                                                    \
                     }                                                        \
                     while(0)
#else
#define ASSERT(expr)
#endif


#endif /* DEBUG_H */
