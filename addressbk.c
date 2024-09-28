#include<stdio.h>
#include<string.h>
struct data{
    char name[30];
    char mobile[11];
    char email[30];
    char address[50];
};
void add_contacts();
void copy(FILE *,FILE*);
void search();
void print();
void edit();
void delete();
int main(){
    char ch='y';
    int choice;
    while (ch=='y' || ch=='Y'){
       printf("1.Add\n 2.search\n 3.print\n 4.edit\n 5.delete\n Enter your choice: ");
       scanf("%d",&choice);
       printf("-----------------------------------------------------------------------\n");
       switch(choice){
        case 1:
            add_contacts();
            break;
        case 2:
            search();
            break;
        case 3:
            print();
            break;
        case 4:
             edit();
             break;
        case 5:
            delete();
            break;
       }
       printf("do you want to continue(y/n): ");
       scanf(" %c",&ch);
       
    
    }
}
void add_contacts(){
    struct data contacts;
    FILE *fdata=fopen("data.csv","r");
    if(fdata== NULL){
        printf("file not opened");
        return;
    }
    int count=0;
    FILE *ftemp=fopen("temp.csv","w");
    fscanf(fdata,"%d\n",&count);
    fprintf(ftemp,"%d\n",count+1);
    for(int i=0;i<count;i++){
        fscanf(fdata,"%[^,],%[^,],%[^,],%[^\n]\n",contacts.name,contacts.mobile,contacts.email,contacts.address);
        fprintf(ftemp,"%s,%s,%s,%s\n",contacts.name,contacts.mobile,contacts.email,contacts.address);
    }
    char str3[40];
    printf("Enter the proper name without special characters and numbers: ");
    scanf(" %[^\n]",str3);
   // __fpurge(stdin);
    char str1[20];
    num1:
       
       printf("Enter the mobile number: ");
       scanf(" %[^\n]",str1);
       fseek(fdata,2,SEEK_SET);
       int flag;
       for(int i=0;i<count;i++){
        flag=0;
        fscanf(fdata,"%[^,],%[^,],%[^,],%[^\n]\n",contacts.name,contacts.mobile,contacts.email,contacts.address);
           
            if(strcmp(str1,contacts.mobile)==0){
              flag=1;
              break;
              
            }
        }
        if(flag==1){
            printf("The Entered mobile number is already exist\n          Try again           \n");
            goto num1;
        }
    int num=strlen(str1);
    if(num>10 || num<10){
        printf("Entered mobile number is incorrect!!\n         Try again          \n");
        goto num1;
    }
    
    strcpy(contacts.mobile,str1);
    char str2[40];
    email1:
    
    printf("Enter the email: ");
    scanf(" %[^\n]",str2);
    int flag3;
    for(int i=0;i<count;i++){
        flag3=0;
        fscanf(fdata,"%[^,],%[^,],%[^,],%[^\n]\n",contacts.name,contacts.mobile,contacts.email,contacts.address);
           
            if(strcmp(str2,contacts.email)==0){
              flag3=1;
              break;
              
            }
        }
        if(flag3==1){
            printf("The Entered Email ID is already exist\n          Try again           \n");
            goto email1;
        }
    for(int i=0;str2[i];i++){
        if(str2[i]=='@'){
            if(strstr(str2,".com")!=NULL){
                if(str2[i+1]=='.'){
                    printf("Enter the correct email_ID\n");
                    goto email1;
                }
            }
        }

    }
  
    strcpy(contacts.email,str2);
    strcpy(contacts.mobile,str1);
    strcpy(contacts.name,str3);
    printf("Enter the address: ");
    scanf(" %[^\n]",contacts.address);
    
    fprintf(ftemp,"%s,%s,%s,%s\n",contacts.name,contacts.mobile,contacts.email,contacts.address);
    fclose(fdata);
    fclose(ftemp);
    fdata=fopen("data.csv","w");
    ftemp=fopen("temp.csv","r");
    copy(fdata,ftemp);
    fclose(fdata);
    fclose(ftemp);
}
void copy(FILE *fdata,FILE *ftemp){
    char ch;
    while((ch =fgetc(ftemp))!=EOF){
        fputc(ch,fdata);
        //ch=fgetc(ftemp);
    }
}
void search(){
    struct data contacts;
    FILE *fdata=fopen("data.csv","r");
    char mobile_num[30];
    int count=0;
    printf("Enter the mobile number to get the details: ");
    scanf(" %[^\n]",mobile_num);
    fscanf(fdata,"%d\n",&count);
    int flag=0;
    for(int i=0;i<count;i++){
        fscanf(fdata,"%[^,],%[^,],%[^,],%[^\n]\n",contacts.name,contacts.mobile,contacts.email,contacts.address);
        if(strcmp(mobile_num,contacts.mobile) == 0)
        {
            printf("-----------------------------------------------------------------------\n");
            printf("Name    : %s\n",contacts.name);
            printf("Mobile  : %s\n",contacts.mobile);
            printf("Email   : %s\n",contacts.email);
            printf("Address : %s\n",contacts.address);
            printf("-----------------------------------------------------------------------\n");
            flag=1;
        }
    }
    if(flag==0){
        printf("Please enter the valid mobile number!\n");
    }
    fclose(fdata);
    
}
void  print(){
    struct data contacts;
    FILE *fdata=fopen("data.csv","r");
    int count=0;
    fscanf(fdata,"%d\n",&count);
    while(!feof(fdata)){
        for(int i=0;i<count;i++)
        {
        fscanf(fdata,"%[^,],%[^,],%[^,],%[^\n]\n",contacts.name,contacts.mobile,contacts.email,contacts.address);
            
            printf("Name    : %s\n",contacts.name);
            printf("Mobile  : %s\n",contacts.mobile);
            printf("Email   : %s\n",contacts.email);
            printf("Address : %s\n",contacts.address);
            printf("-----------------------------------------------------------------------\n");
            
        }
    }
    fclose(fdata);
}
void edit(){
    int var=1;
    int opt;
    int count=0;
    char new_name[30];
    char new_mobile[15];
    char new_mobile1[15];
    char new_email[30];
    char new_address[30];
    struct data contacts;
    FILE *fdata=fopen("data.csv","r");
    FILE *ftemp=fopen("temp.csv","w");
    printf("Enter the mobile number to edit the details: ");
    scanf(" %[^\n]",new_mobile);
    fscanf(fdata,"%d\n",&count);
    fprintf(ftemp,"%d\n",count);
    int flag=0;
    for(int i=0;i<count;i++){
        fscanf(fdata,"%[^,],%[^,],%[^,],%[^\n]\n",contacts.name,contacts.mobile,contacts.email,contacts.address);
      if(strcmp(new_mobile,contacts.mobile) == 0){
        flag=1;
        while(var){
           printf("1: Name \n 2:Email \n 3:Address\n 4:Mobile\n 5:exit\n");
           printf("Enter your choices:  \n");
           scanf("%d",&opt);
           switch (opt)
           {
            case 1:
            printf("Enter the new name: \n");
            scanf(" %[^\n]",new_name);
            strcpy(contacts.name,new_name);
            break;
            case 2:
            email2:
            printf("Enter the new Email  \n");
            scanf(" %[^\n]",new_email);
            int flag4;
            for(int i=0;i<count;i++){
            flag4=0;
            if(strcmp(new_email,contacts.email)==0){
              flag4=1;
              break;
              
            }
            }
            if(flag4==1){
                printf("The Entered Email ID is already exist\n          Try again           \n");
                goto email2;
            }
            for(int i=0;new_email[i];i++){
            if(new_email[i]=='@'){
                if(strstr(new_email,".com")!=NULL){
                    if(new_email[i+1]=='.'){
                      printf("Enter the correct email_ID\n");
                      goto email2;
                }
               }
              }
            }
            strcpy(contacts.email,new_email);
            break;
            case 3:
            printf("Enter the new address: \n");
            scanf(" %[^\n]",new_address);
            strcpy(contacts.address,new_address);
            break;
            case 4:
            new:
            printf("Enter the mobile number: ");
            scanf(" %[^\n]",new_mobile1);
            //fseek(fdata,2,SEEK_SET);
            int flag5;
            for(int i=0;i<count;i++){
              flag5=0;
            if(strcmp(new_mobile1,contacts.mobile)==0)
                {
                  flag5=1;
                  break;
                }
            }
            if(flag5==1){
                printf("The Entered mobile number is already exist\n          Try again           \n");
                   goto new;
            }
            int num2=strlen(new_mobile1);
            if(num2>10 || num2<10){
                printf("Entered mobile number is incorrect!!\n         Try again          \n");
                   goto new;
            }
            strcpy(contacts.mobile,new_mobile1);
            case 5:
               var=0;
               break;
            }
        }
    }
    
       fprintf(ftemp,"%s,%s,%s,%s\n",contacts.name,contacts.mobile,contacts.email,contacts.address);
    }
    if(flag==0){
        printf("Please enter the valid mobile number!\n");
    }
    fclose(fdata);
    fclose(ftemp);
    fdata=fopen("data.csv","w");
    ftemp=fopen("temp.csv","r");
    copy(fdata,ftemp);
    fclose(fdata);
    fclose(ftemp);
}
void delete(){
    struct data contacts;
    char new_mobile[20];
    int count=0;
    FILE *fdata=fopen("data.csv","r");
    FILE *ftemp=fopen("temp.csv","w");
    fprintf(ftemp," %c",'\n');
    printf("Enter the mobile number to delete the data:");
    scanf(" %[^\n]",new_mobile);
    fscanf(fdata,"%d\n",&count);
    int flag=0;
    while(!feof(fdata)){
        for(int i=0;i<count;i++){
            fscanf(fdata,"%[^,],%[^,],%[^,],%[^\n]\n",contacts.name,contacts.mobile,contacts.email,contacts.address);
            if (strcmp(new_mobile,contacts.mobile)==0)
            {
                flag=1;
                printf("Deleted Successfully!\n");
                continue;
            }
            else
            {
                fprintf(ftemp,"%s,%s,%s,%s\n",contacts.name,contacts.mobile,contacts.email,contacts.address); 
            }
        }
    }
    if(flag==0){
        printf("Please enter the valid mobile number!\n");
        count=count+1;
    }

    rewind(ftemp);
    fprintf(ftemp,"%d",count-1);
    fclose(fdata);
    fclose(ftemp);
    fdata=fopen("data.csv","w");
    ftemp=fopen("temp.csv","r");
    copy(fdata,ftemp);
    fclose(fdata);
    fclose(ftemp);
}



