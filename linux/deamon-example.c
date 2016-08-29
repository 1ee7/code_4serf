1�� init.c�嵥


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
21   exit(0);//�Ǹ����̣�����������,���ѻỰ�鳤��ݡ�
22 
23  else if(pid< 0)
24 
25   exit(1);//forkʧ�ܣ��˳�
26 
27  //�ǵ�һ�ӽ��̣���̨����ִ��
28 
29  setsid();
30 
31  //��һ�ӽ��̳�Ϊ�µĻỰ�鳤�ͽ����鳤
32 
33  //��������� �˷���
34 
35  if(pid=fork())
36 
37   exit(0);//�ǵ�һ�ӽ��̣�������һ�ӽ���
38 
39  else if(pid< 0)
40 
41   exit(1);//forkʧ�ܣ��˳�
42 
43  //�ǵڶ��ӽ��̣�����
44 
45  //�ڶ��ӽ��̲����ǻỰ�鳤��Ҳ�Ͳ�������򿪿����նˡ�
46 
47  for(i=0;i< NOFILE;++i)
48 
49   //�رմ򿪵��ļ�������
50 
51   close(i);
52 
53   chdir("/tmp"); //�ı乤��Ŀ¼��/tmp
54 
55   umask(0);//���� �ļ�������ģ
56 
57   return;
58 
59  }

 

2�� test.c�嵥


 1 #include < stdio.h >
 2 
 3 #include < time.h >
 4 
 5 void init_daemon(void);//�ػ����̳�ʼ������
 6 
 7 main()
 8 
 9 {
10 
11  FILE *fp;time_t t;
12 
13  init_daemon();//��ʼ��ΪDaemon
14 
15  while(1)//ÿ��һ������test.log��������״̬
16 
17  {
18 
19    sleep(60);//˯ ��һ����
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


���룺gcc -g -o test init.c test.c

ִ�У�./test

�鿴���̣�ps -ef