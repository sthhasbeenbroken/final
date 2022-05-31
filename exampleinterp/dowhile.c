int main() {
    int i;
    i=0;
   do {
        print "%d" i;
        //i++;//编译时栈溢出
        i=i+1;
   }  
   while(i<4);

}