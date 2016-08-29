1． init.c清单


 1 #include < unistd.h >
 2 
 3 #include < signal.h >
 4 
 5 #include < sys/param.h >
 6 
 7 #include < sys/types.h >
 8 
 9 #include < sys/stat.h >
10 
11 void init_daemon(void)
12 
13 {
14 
15  int pid;
16 
17  int i;
18 
19  if(pid=fork())
20 
21   exit(0);//是父进程，结束父进程,摆脱会话组长身份。
22 
23  else if(pid< 0)
24 
25   exit(1);//fork失败，退出
26 
27  //是第一子进程，后台继续执行
28 
29  setsid();
30 
31  //第一子进程成为新的会话组长和进程组长
32 
33  //并与控制终 端分离
34 
35  if(pid=fork())
36 
37   exit(0);//是第一子进程，结束第一子进程
38 
39  else if(pid< 0)
40 
41   exit(1);//fork失败，退出
42 
43  //是第二子进程，继续
44 
45  //第二子进程不再是会话组长，也就不会请求打开控制终端。
46 
47  for(i=0;i< NOFILE;++i)
48 
49   //关闭打开的文件描述符
50 
51   close(i);
52 
53   chdir("/tmp"); //改变工作目录到/tmp
54 
55   umask(0);//重设 文件创建掩模
56 
57   return;
58 
59  }

 

2． test.c清单


 1 #include < stdio.h >
 2 
 3 #include < time.h >
 4 
 5 void init_daemon(void);//守护进程初始化函数
 6 
 7 main()
 8 
 9 {
10 
11  FILE *fp;time_t t;
12 
13  init_daemon();//初始化为Daemon
14 
15  while(1)//每隔一分钟向test.log报告运行状态
16 
17  {
18 
19    sleep(60);//睡 眠一分钟
20 
21    if((fp=fopen("test.log","a")) >=0)
22 
23    {t=time(0);
24 
25     fprintf(fp,"Im here at %sn",asctime(localtime(&t)) );
26 
27     fclose(fp);}
28 
29    }
30 
31 }


编译：gcc -g -o test init.c test.c

执行：./test

查看进程：ps -ef