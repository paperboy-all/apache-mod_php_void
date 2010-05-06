/* 
**  mod_php_void.c -- Apache sample php_void module
**  [Autogenerated via ``apxs -n php_void -g'']
**
**  To play with this sample module first compile it into a
**  DSO file and install it into Apache's modules directory 
**  by running:
**
**    $ apxs -c -i mod_php_void.c
**
**  Then activate it in Apache's httpd.conf file for instance
**  for the URL /php_void in as follows:
**
**    #   httpd.conf
**    LoadModule php_void_module modules/mod_php_void.so
**
**  Then after restarting Apache via
**
**    $ apachectl restart
*/

#include "httpd.h"
#include "http_config.h"
#include "http_protocol.h"
#include "ap_config.h"

static const char *php_void_apache_value_handler(cmd_parms *cmd,
                                                 void *dummy,
                                                 const char *name,
                                                 const char *value)
{
    return NULL;
}

/* SEE ALSO http://blog.endflow.net/?lang=ja&p=48 */
const command_rec php_void_dir_cmds[] =
{
    AP_INIT_TAKE2("php_value",       php_void_apache_value_handler, NULL, OR_OPTIONS, "PHP Value Modifier"),
    AP_INIT_TAKE2("php_flag",        php_void_apache_value_handler, NULL, OR_OPTIONS, "PHP Flag Modifier"),
    {NULL}
};

/* Dispatch list for API hooks */
module AP_MODULE_DECLARE_DATA php_void_module = {
    STANDARD20_MODULE_STUFF,
    NULL,                    /* create per-dir    config structures */
    NULL,                    /* merge  per-dir    config structures */
    NULL,                    /* create per-server config structures */
    NULL,                    /* merge  per-server config structures */
    php_void_dir_cmds,       /* table of config file commands       */
    NULL                     /* register hooks                      */
};
