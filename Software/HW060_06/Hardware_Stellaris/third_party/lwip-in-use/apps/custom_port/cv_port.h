#ifndef __CV_PORT_H__
#define __CV_PORT_H__

void cv_port_init(void);

/* The maximum number of parameters that the CGI handler can be sent. */
#ifndef MAX_CGI_PARAMETERS
#define MAX_CGI_PARAMETERS 16

#endif

#ifdef INCLUDE_HTTPD_SSI

typedef int (*tSSIHandler)(int iIndex, char *pcInsert, int iInsertLen);

void http_set_ssi_handler(tSSIHandler pfnSSIHandler,
                          const char **ppcTags, int iNumTags);

/* The maximum length of the string comprising the tag name */
#ifndef MAX_TAG_NAME_LEN
#define MAX_TAG_NAME_LEN 8
#endif

/* The maximum length of string that can be returned to replace any given tag */
#ifndef MAX_TAG_INSERT_LEN
#define MAX_TAG_INSERT_LEN 192
#endif

#endif

#endif /* __CV_PORT_H__ */
