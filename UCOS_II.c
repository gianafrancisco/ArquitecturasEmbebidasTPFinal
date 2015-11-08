/*
*********************************************************************************************************
*                                                uC/OS-II
*                                          The Real-Time Kernel
*
*                          (c) Copyright 1992-2002, Jean J. Labrosse, Weston, FL
*                                           All Rights Reserved
*
* File : uCOS_II.C
* By   : Jean J. Labrosse
*********************************************************************************************************
*/

#define  OS_GLOBALS                           /* Declare GLOBAL variables                              */
#include "includes.h"


#define  OS_MASTER_FILE                       /* Prevent the following files from including includes.h */
/* Microchip PIC18xxx specific */

#include "/home/francisco/SOFTWARE_PIC/uCOS-II/PIC18/Practico_4x/os_core.c"
/* End Microchip PIC18xxx specific */
/*
#include "\software_pic\ucos-ii\source\os_flag.c"
#include "\software_pic\ucos-ii\source\os_mbox.c"
#include "\software_pic\ucos-ii\source\os_mem.c"
#include "\software_pic\ucos-ii\source\os_mutex.c"
#include "\software_pic\ucos-ii\source\os_q.c"
#include "\software_pic\ucos-ii\source\os_sem.c"
#include "\software_pic\ucos-ii\source\os_task.c"
#include "\software_pic\ucos-ii\source\os_time.c"
*/
#include "/home/francisco/SOFTWARE_PIC/uCOS-II/SOURCE/os_flag.c"
#include "/home/francisco/SOFTWARE_PIC/uCOS-II/SOURCE/os_mbox.c"
#include "/home/francisco/SOFTWARE_PIC/uCOS-II/SOURCE/os_mem.c"
#include "/home/francisco/SOFTWARE_PIC/uCOS-II/SOURCE/os_mutex.c"
#include "/home/francisco/SOFTWARE_PIC/uCOS-II/SOURCE/os_q.c"
#include "/home/francisco/SOFTWARE_PIC/uCOS-II/SOURCE/os_sem.c"
#include "/home/francisco/SOFTWARE_PIC/uCOS-II/SOURCE/os_task.c"
#include "/home/francisco/SOFTWARE_PIC/uCOS-II/SOURCE/os_time.c"
