#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <grp.h>
#include <pwd.h>
#include <fcntl.h>


struct stat stat1,stat2;
struct tm *time1, *time2;

void filestat1(void);
void filestat2(void);
void filetime1(void);
void filetime2(void);
void sizecmp(void);
void blockcmp(void);
void datecmp(void);
void timecmp(void);

int main(void)
{
   filestat1();
   filestat2();
   filetime1();
   filetime2();
   sizecmp();
   blockcmp();
   datecmp();
   timecmp();
}

// load file info (file name : test1, test2)
void filestat1(void)
{
	printf("[File Stat 1]\n");
	DIR *dirp;
	struct dirent *dir_entry;
	int return_stat;
	char *file_name;
	struct stat file_info;
	struct tm *tminfo;
	mode_t file_mode;
	struct passwd *my_passwd;
	struct group *my_group;
	char buf1[80];

	if( (dirp = opendir(".")) == NULL )
		exit(0);

	while( dir_entry = readdir(dirp)) {
		if( strcmp(dir_entry->d_name,"text1") == 1 || strcmp(dir_entry->d_name,"text2") == 1 ) {

			printf("\t%s :",dir_entry->d_name);
			if ( (return_stat = stat(dir_entry->d_name, &file_info)) == -1 ) {
				perror("Error : ");
				exit(0);
			}

				
			// print set mode
			file_mode = file_info.st_mode;
				
			if( S_ISDIR(file_mode)) printf("d");
			else printf("-");

			if( file_mode & S_IRUSR) printf("r");
			else printf("-");

			if( file_mode & S_IWUSR) printf("w");
			else printf("-");
	
			if( file_mode & S_IXUSR) printf("x");
			else printf("-");

			if( file_mode & S_IRGRP) printf("r");
			else printf("-");

			if( file_mode & S_IWGRP) printf("w");
			else printf("-");

			if( file_mode & S_IXGRP) printf("x");
			else printf("-");

			if( file_mode & S_IROTH) printf("r");
			else printf("-");

			if( file_mode & S_IWOTH) printf("w");
			else printf("-");

			if( file_mode & S_IXOTH) printf("x");
			else printf("-");

			printf(" ");

			// print file information
			printf("%d ",file_info.st_nlink);

			// set user id and group id
			my_passwd = getpwuid(file_info.st_uid);
			my_group = getgrgid(file_info.st_gid);

			// print user id and group id
			printf("%s ", my_passwd -> pw_name);
			printf("%s ", my_group -> gr_name);
			printf("%ld ", file_info.st_size);

			// set format to time
			tminfo = localtime (&(file_info.st_atime));
			strftime(buf1, 80, "%mM %dD  %H: %M", tminfo);
			printf("%s\n",buf1);


		}
	}
	closedir(dirp);

	
}

// load file update time(file name : test1, test2)
void filestat2(void)
{
	printf("[File Stat 2]\n");
	DIR *dirp;
	struct dirent *dir_entry;
	int return_stat;
	char *file_name;
	struct stat file_info;
	struct tm *tminfo;
	mode_t file_mode;
	struct passwd *my_passwd;
	struct group *my_group;
	char buf1[80];

	if( (dirp = opendir(".")) == NULL )
		exit(0);

	while( dir_entry = readdir(dirp)) {
		if( strcmp(dir_entry->d_name,"test1") == 1 || strcmp(dir_entry->d_name,"test2") == 1 ) {

			printf("\t%s :",dir_entry->d_name);
			if ( (return_stat = stat(dir_entry->d_name, &file_info)) == -1 ) {
				perror("Error : ");
				exit(0);
			}
				
		
			// print set mode
			file_mode = file_info.st_mode;

			printf(" ");

			// print file information
			printf("%d ",file_info.st_nlink);


			// set format to time
			tminfo = localtime (&(file_info.st_atime));
			strftime(buf1, 80, "%mM %dD  %H: %M", tminfo);
			printf("%s\n",buf1);


		}
	}
	closedir(dirp);

}
void filetime1(void)
{}
void filetime2(void)
{}
void sizecmp(void)
{
	struct stat buf1,buf2; 
 	struct tm* time; 
 
 
 	int size1,size2; 
 
 
 	stat("text1",&buf1); 
 	stat("text2",&buf2); 
 	//get text1,text2 data 
 	//printf("size : %d\n", (int)buf1.st_size); 
 	//printf("size : %d\n", (int)buf2.st_size); 
 	size1=(int)buf1.st_size; 
 	size2=(int)buf2.st_size; 
 	//get size of text1,text2 
 
 
 	if(size1>size2) 
 	{ 
 		printf("%s is bigger\n","test1"); 
 	} 
 	else 
 	{ 
 		printf("%s is bigger\n","test2"); 
 	} 
 	//size compare 

}
void blockcmp(void)
{}
void datecmp(void)
{}
void timecmp(void)
{}
