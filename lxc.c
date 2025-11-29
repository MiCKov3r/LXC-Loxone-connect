// LXC - Loxone Connect v1.3
// Get string values into Loxone Miniserver via HTTP/XML

char* t1;
char* t2;
char* t3;
char* val;
char* ret;
char* server;

while(1) {
    if(getinput(0) > 0) {
        t1 = getinputtext(0);
        t2 = getinputtext(1);
        t3 = getinputtext(2);
        
        // Use custom server if provided, otherwise use default
        if(strlen(t1) > 0) {
            server = t1;
        } else {
            server = "185.227.171.228:11881";
        }
        
        val = httpget(server, t2);
        
        if(val != NULL) {
            ret = getxmlvalue(val, 0, t3);
            
            if(ret != NULL) {
                setoutputtext(0, ret);
                free(ret);
            } else {
                setoutputtext(0, "XML error");
            }
            free(val);
        } else {
            setoutputtext(0, "HTTP error");
        }
        
        free(t1);
        free(t2);
        free(t3);
    } else {
        setoutputtext(0, "");
    }
    
    sleep(1000);
}
