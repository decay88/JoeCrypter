#ifndef _SHERROR_H
#define _SHERROR_H

/* Shell API specific error code definitions */

#if __POCC__ >= 500
#pragma once
#endif

#include <winerror.h>

#define COPYENGINE_S_YES  _HRESULT_TYPEDEF_(0x00270001L)
#define COPYENGINE_S_NOT_HANDLED  _HRESULT_TYPEDEF_(0x00270003L)
#define COPYENGINE_S_USER_RETRY  _HRESULT_TYPEDEF_(0x00270004L)
#define COPYENGINE_S_USER_IGNORED  _HRESULT_TYPEDEF_(0x00270005L)
#define COPYENGINE_S_MERGE  _HRESULT_TYPEDEF_(0x00270006L)
#define COPYENGINE_S_DONT_PROCESS_CHILDREN  _HRESULT_TYPEDEF_(0x00270008L)
#define COPYENGINE_S_ALREADY_DONE  _HRESULT_TYPEDEF_(0x0027000AL)
#define COPYENGINE_S_PENDING  _HRESULT_TYPEDEF_(0x0027000BL)
#define COPYENGINE_S_KEEP_BOTH  _HRESULT_TYPEDEF_(0x0027000CL)
#define COPYENGINE_S_CLOSE_PROGRAM  _HRESULT_TYPEDEF_(0x0027000DL)

#define COPYENGINE_E_USER_CANCELLED  _HRESULT_TYPEDEF_(0x80270000L)
#define COPYENGINE_E_CANCELLED  _HRESULT_TYPEDEF_(0x80270001L)
#define COPYENGINE_E_REQUIRES_ELEVATION  _HRESULT_TYPEDEF_(0x80270002L)

#define COPYENGINE_E_SAME_FILE  _HRESULT_TYPEDEF_(0x80270003L)
#define COPYENGINE_E_DIFF_DIR  _HRESULT_TYPEDEF_(0x80270004L)
#define COPYENGINE_E_MANY_SRC_1_DEST  _HRESULT_TYPEDEF_(0x80270005L)

#define COPYENGINE_E_DEST_SUBTREE  _HRESULT_TYPEDEF_(0x80270009L)
#define COPYENGINE_E_DEST_SAME_TREE  _HRESULT_TYPEDEF_(0x8027000AL)

#define COPYENGINE_E_FLD_IS_FILE_DEST  _HRESULT_TYPEDEF_(0x8027000BL)
#define COPYENGINE_E_FILE_IS_FLD_DEST  _HRESULT_TYPEDEF_(0x8027000CL)

#define COPYENGINE_E_FILE_TOO_LARGE  _HRESULT_TYPEDEF_(0x8027000DL)
#define COPYENGINE_E_REMOVABLE_FULL  _HRESULT_TYPEDEF_(0x8027000EL)

#define COPYENGINE_E_DEST_IS_RO_CD  _HRESULT_TYPEDEF_(0x8027000FL)
#define COPYENGINE_E_DEST_IS_RW_CD  _HRESULT_TYPEDEF_(0x80270010L)
#define COPYENGINE_E_DEST_IS_R_CD  _HRESULT_TYPEDEF_(0x80270011L)

#define COPYENGINE_E_DEST_IS_RO_DVD  _HRESULT_TYPEDEF_(0x80270012L)
#define COPYENGINE_E_DEST_IS_RW_DVD  _HRESULT_TYPEDEF_(0x80270013L)
#define COPYENGINE_E_DEST_IS_R_DVD  _HRESULT_TYPEDEF_(0x80270014L)

#define COPYENGINE_E_SRC_IS_RO_CD  _HRESULT_TYPEDEF_(0x80270015L)
#define COPYENGINE_E_SRC_IS_RW_CD  _HRESULT_TYPEDEF_(0x80270016L)
#define COPYENGINE_E_SRC_IS_R_CD  _HRESULT_TYPEDEF_(0x80270017L)

#define COPYENGINE_E_SRC_IS_RO_DVD  _HRESULT_TYPEDEF_(0x80270018L)
#define COPYENGINE_E_SRC_IS_RW_DVD  _HRESULT_TYPEDEF_(0x80270019L)
#define COPYENGINE_E_SRC_IS_R_DVD  _HRESULT_TYPEDEF_(0x8027001AL)

#define COPYENGINE_E_INVALID_FILES_SRC  _HRESULT_TYPEDEF_(0x8027001BL)
#define COPYENGINE_E_INVALID_FILES_DEST  _HRESULT_TYPEDEF_(0x8027001CL)
#define COPYENGINE_E_PATH_TOO_DEEP_SRC  _HRESULT_TYPEDEF_(0x8027001DL)
#define COPYENGINE_E_PATH_TOO_DEEP_DEST  _HRESULT_TYPEDEF_(0x8027001EL)
#define COPYENGINE_E_ROOT_DIR_SRC  _HRESULT_TYPEDEF_(0x8027001FL)
#define COPYENGINE_E_ROOT_DIR_DEST  _HRESULT_TYPEDEF_(0x80270020L)
#define COPYENGINE_E_ACCESS_DENIED_SRC  _HRESULT_TYPEDEF_(0x80270021L)
#define COPYENGINE_E_ACCESS_DENIED_DEST  _HRESULT_TYPEDEF_(0x80270022L)
#define COPYENGINE_E_PATH_NOT_FOUND_SRC  _HRESULT_TYPEDEF_(0x80270023L)
#define COPYENGINE_E_PATH_NOT_FOUND_DEST _HRESULT_TYPEDEF_(0x80270024L)
#define COPYENGINE_E_NET_DISCONNECT_SRC  _HRESULT_TYPEDEF_(0x80270025L)
#define COPYENGINE_E_NET_DISCONNECT_DEST  _HRESULT_TYPEDEF_(0x80270026L)
#define COPYENGINE_E_SHARING_VIOLATION_SRC  _HRESULT_TYPEDEF_(0x80270027L)
#define COPYENGINE_E_SHARING_VIOLATION_DEST  _HRESULT_TYPEDEF_(0x80270028L)

#define COPYENGINE_E_ALREADY_EXISTS_NORMAL  _HRESULT_TYPEDEF_(0x80270029L)
#define COPYENGINE_E_ALREADY_EXISTS_READONLY  _HRESULT_TYPEDEF_(0x8027002AL)
#define COPYENGINE_E_ALREADY_EXISTS_SYSTEM  _HRESULT_TYPEDEF_(0x8027002BL)
#define COPYENGINE_E_ALREADY_EXISTS_FOLDER  _HRESULT_TYPEDEF_(0x8027002CL)
#define COPYENGINE_E_STREAM_LOSS  _HRESULT_TYPEDEF_(0x8027002DL)
#define COPYENGINE_E_EA_LOSS  _HRESULT_TYPEDEF_(0x8027002EL)
#define COPYENGINE_E_PROPERTY_LOSS  _HRESULT_TYPEDEF_(0x8027002FL)
#define COPYENGINE_E_PROPERTIES_LOSS  _HRESULT_TYPEDEF_(0x80270030L)
#define COPYENGINE_E_ENCRYPTION_LOSS  _HRESULT_TYPEDEF_(0x80270031L)
#define COPYENGINE_E_DISK_FULL  _HRESULT_TYPEDEF_(0x80270032L)
#define COPYENGINE_E_DISK_FULL_CLEAN  _HRESULT_TYPEDEF_(0x80270033L)
#define COPYENGINE_E_CANT_REACH_SOURCE  _HRESULT_TYPEDEF_(0x80270035L)

#define COPYENGINE_E_RECYCLE_UNKNOWN_ERROR  _HRESULT_TYPEDEF_(0x80270035L)
#define COPYENGINE_E_RECYCLE_FORCE_NUKE  _HRESULT_TYPEDEF_(0x80270036L)
#define COPYENGINE_E_RECYCLE_SIZE_TOO_BIG  _HRESULT_TYPEDEF_(0x80270037L)
#define COPYENGINE_E_RECYCLE_PATH_TOO_LONG  _HRESULT_TYPEDEF_(0x80270038L)
#define COPYENGINE_E_RECYCLE_BIN_NOT_FOUND  _HRESULT_TYPEDEF_(0x8027003AL)
#define COPYENGINE_E_NEWFILE_NAME_TOO_LONG  _HRESULT_TYPEDEF_(0x8027003BL)
#define COPYENGINE_E_NEWFOLDER_NAME_TOO_LONG  _HRESULT_TYPEDEF_(0x8027003CL)
#define COPYENGINE_E_DIR_NOT_EMPTY  _HRESULT_TYPEDEF_(0x8027003DL)

#define NETCACHE_E_NEGATIVE_CACHE  _HRESULT_TYPEDEF_(0x80270100L)
#define EXECUTE_E_LAUNCH_APPLICATION  _HRESULT_TYPEDEF_(0x80270101L)
#define SHELL_E_WRONG_BITDEPTH  _HRESULT_TYPEDEF_(0x80270102L)

#endif /* _SHERROR_H */