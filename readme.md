### 报错：cgi_header: unable to find LFLF
排除各种权限以及html头必须换两行等各种情况后，终于找到原因，最后执行一下:`fflush(cgiOut);`搞定。