/*
 * AUTHORS : <jonathanmarpaung88@gmail.com>
 * VERSION : 1.0.0
 * TYPE    : Header
 * LICENSE : MIT
 */
/* Make guard for this header */
#ifndef FGTL_FILE_HEADER_H
#define FGTL_FILE_HEADER_H

/*
 * If you see code
 * #ifdef __cplusplus
 * extern "C" {
 * #endif
 * 
 * This used for, make if you use the c++ compiler, 
 * it will be extern in c language
 */

#ifdef __cplusplus
extern "C" {
#endif
	/*
	 * @parameter { const char* { Path } }
	 * This function used for get all
	 * list file, (Filter file or directory)
	 */
	char* FGTL_Get_List_File(const char* path);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
	/*
	 * @parameter { const char* { Path } }
	 * This function used for get all
	 * list file, (Filter file or directory)
	 * with check the extension
	 */
	char* FGTL_Get_List_File_Extension(const char* path, \
		const char* extension);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
	/*
	 * @parameter { const char* { Path } }
	 * This function used for get all
	 * list folder, (Filter folder or file)
	 */
	char* FGTL_Get_List_Folder(const char* path);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
	/*
	 * @parameter { const char* { Path } }
	 * This function used for get all
	 * content in directory
	 */
	char* FGTL_Get_List(const char* path);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
	/*
	 * @parameter { const char* { Path / Or File } }
	 * This function used for check the parameter
	 * it's folder or file (if folder true) |
	 * (if file false)
	 */
	int FGTL_Its_Folder(const char* path_or_file);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
	/*
	 * @parameter { const char* { Path / Or File } }
	 * This function used for check exist file
	 * or directory
	 */
	int FGTL_Exist_Content(const char* path_or_file);
#ifdef __cplusplus
}
#endif

#endif /* End of FGTL_FILE_HEADER_H */