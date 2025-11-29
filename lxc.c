// LXC - Loxone connect v1.2
char* t2;
char* t3;
char* val;
char* ret;

while(1) {
    if(getinput(0) > 0) {
        t2 = getinputtext(1);
        t3 = getinputtext(2);
        
        val = httpget("YOUR_SERVER_IP:PORT", t2);
        
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
        
        free(t2);
        free(t3);
    } else {
        setoutputtext(0, "");
    }
    
    sleep(1000);
}
