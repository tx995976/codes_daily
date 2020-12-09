int getindex(char *s){
    if(!strcmp(s,"Monday"))
        return 1;
    else if(!strcmp(s,"Tuesday"))
        return 2;
    else if(!strcmp(s,"Thursday"))
        return 3;   
    else if(!strcmp(s,"Wednesday"))
        return 4;
    else if(!strcmp(s,"Friday"))
        return 5;
    else if(!strcmp(s,"Saturday"))
        return 6;
    else if(!strcmp(s,"Sunday"))
        return 7;
    else
        return -1;
}