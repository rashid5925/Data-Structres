#include <iostream>

using namespace std;


struct Student{
	int id;
	float marks;
};



Student s[5];
int startIndex = -1, lastIndex = -1;

void display();
void insertEnd();
void insertStart();
void insertBefore();
void insertAfter();
void deleteStart();
void deleteEnd();
void deleteAfter();
void deleteBefore();
void deleteSpecific();

int main(){
	int exit = 1;
	
	do{
		cout<<"Enter operation number to perform operation\n"
		<<"1. Display\n"
		<<"2. Insert at end\n"
		<<"3. Insert at start\n"
		<<"4. Insert after specific\n"
		<<"5. Insert before specific\n"
		<<"6. Delete from start\n"
		<<"7. Delete from end\n"
		<<"8. Delete before specific\n"
		<<"9. Delete after specific\n"
		<<"10. Delete specific\n"
		<<"0. Exit\n";
		
		cin>>exit;
		
		switch(exit){
			case 1:
				display();
				break;
			case 2:
				insertEnd();
				break;
			case 3:
				insertStart();
				break;
			case 4:
				insertBefore();
				break;
			case 5:
				insertAfter();
				break;
			case 6:
				deleteStart();
				break;
			case 7:
				deleteEnd();
				break;
			case 8:
				deleteAfter();
				break;
			case 9:
				deleteBefore();
				break;
			case 10:
				deleteSpecific();
				break;
			case 0:
				cout<<"Exiting....";
				break;
			default:
				cout<<"Wrong Input";
				break;
		}
	}while(exit!=0);
	
	return 0;
}


int search(Student arr[5], int id){
	for(int i=startIndex; i<lastIndex; i++){
		if(arr[i].id==id){
			return i;
		}
	}
	return -1;
}

void display(){
	cout<<"\n";
	for(int i=startIndex; i<lastIndex; i++){
		cout<<"Id: "<<s[i].id<<"  marks: "<<s[i].marks<<endl;
	}
	cout<<"\n";
}

void insertEnd(){
	if (startIndex==0 && lastIndex==5){
        cout<<"No space\n";
    }else if (lastIndex==5 && startIndex!=0){
    	int count = startIndex;
    	while (count<=lastIndex){
    		s[count-1] = s[count];
    		count++;
		}
		startIndex--;
		cout<<"Enter id of student";
		cin>>s[startIndex].id;
		cout<<"Enter marks of student";
		cin>>s[startIndex].marks;
	}else if (lastIndex==-1 && startIndex==-1){
        startIndex++;
        cout<<"Enter id of student: ";
        cin>>s[startIndex].id;
        cout<<"Enter marks of student: ";
		cin>>s[startIndex].marks;
        lastIndex = 1;
    }else{
        cout<<"Enter id of student: ";
        cin>>s[lastIndex].id;
        cout<<"Enter marks of student: ";
		cin>>s[lastIndex].marks;
        lastIndex++;
    }
	
}

void insertStart(){
	if (startIndex==-1 && lastIndex==-1){
        startIndex++;
        cout<<"Enter id of student: ";
        cin>>s[startIndex].id;
        cout<<"Enter marks of student: ";
		cin>>s[startIndex].marks;
        lastIndex = 1;
    }else if (startIndex==0 && lastIndex==50){
        cout<<"No space\n";
    }else if (startIndex>0){
        startIndex--;
        cout<<"Enter id of student: ";
        cin>>s[startIndex].id;
        cout<<"Enter marks of student: ";
		cin>>s[startIndex].marks;
    }else{
        int count = lastIndex;
        while (count>=startIndex){
            s[count+1] = s[count];
            count--;
        }
        cout<<"Enter id of student: ";
        cin>>s[startIndex].id;
        cout<<"Enter marks of student: ";
		cin>>s[startIndex].marks;
        lastIndex++;
    }
}

void insertBefore(){
	if (startIndex==0 && lastIndex==50){
        cout<<"No space\n";
    }else if (startIndex==-1 && lastIndex==-1){
        startIndex++;
        cout<<"Enter id of student: ";
        cin>>s[startIndex].id;
        cout<<"Enter marks of student: ";
		cin>>s[startIndex].marks;
        lastIndex = 1;
    }else if (lastIndex<50){
        int id;
        cout<<"Enter id before which to be inserted: ";
        cin>>id;
        std::cout<<"\n";
        int index = search(s, id);
        if (index==-1){
            cout<<"Id not found\n";
            return;
        }
        int count = lastIndex;
        while (count>=index){
            s[count+1] = s[count];
            count--;
        }
        cout<<"Enter id of student: ";
        cin>>s[index].id;
        cout<<"Enter marks of student: ";
		cin>>s[index].marks;
        lastIndex++;
    }else{
        int id;
        cout<<"Enter id before which to be inserted: ";
        cin>>id;
        std::cout<<"\n";
        int index = search(s, id);
        if (index==-1){
            cout<<"Id not found\n";
            return;
        }
        int count = startIndex;
        while (count<index){
            s[count-1] = s[count];
            count++;
        }
        cout<<"Enter id of student: ";
        cin>>s[index-1].id;
        cout<<"Enter marks of student: ";
		cin>>s[index-1].marks;
        startIndex--;
    }
}

void insertAfter(){
	if (startIndex==0 && lastIndex==50){
        cout<<"No space\n";
    }else if (startIndex==-1 && lastIndex==-1){
        startIndex++;
        cout<<"Enter id of student: ";
        cin>>s[startIndex].id;
        cout<<"Enter marks of student: ";
		cin>>s[startIndex].marks;
        lastIndex = 1;
    }else if (lastIndex<50){
        int id;
        cout<<"Enter id after which to be inserted: ";
        cin>>id;
        std::cout<<"\n";
        int index = search(s, id);
        if (index==-1){
            cout<<"Id not found\n";
            return;
        }
        int count = lastIndex;
        while (count>index){
            s[count+1] = s[count];
            count--;
        }
        cout<<"Enter id of student: ";
        cin>>s[index+1].id;
        cout<<"Enter marks of student: ";
		cin>>s[index+1].marks;
        lastIndex++;
    }else{
        int id;
        cout<<"Enter id after which to be inserted: ";
        cin>>id;
        std::cout<<"\n";
        int index = search(s, id);
        if (index==-1){
            cout<<"Id not found\n";
            return;
        }
        int count = startIndex;
        while (count<=index){
            s[count-1] = s[count];
            count++;
        }
        cout<<"Enter id of student: ";
        cin>>s[index].id;
        cout<<"Enter marks of student: ";
		cin>>s[index].marks;
        startIndex--;
    }
}

void deleteStart(){
	if (startIndex==-1){
        cout<<"Empty\n";
    }else if (lastIndex==0){
        cout<<"Only 1 element found and deleted\n";
        startIndex = lastIndex = -1;
    }else{
        startIndex++;
    }
}

void deleteEnd(){
	if (startIndex==-1){
        cout<<"Empty\n";
    }else if (lastIndex==0){
        cout<<"Only 1 element found and deleted\n";
        startIndex = lastIndex = -1;
    }else{
        lastIndex--;
    }
}

void deleteAfter(){
	 if (startIndex==-1){
        cout<<"Empty\n";
    }else if (lastIndex==0){
        cout<<"Only 1 element found and deleted\n";
        startIndex = lastIndex = -1;
    }else{
        int id;
        cout<<"Enter id after which to be inserted: ";
        cin>>id;
        std::cout<<"\n";
        int index = search(s, id);
        if (index==-1){
            std::cout<<"Id not found\n";
            std::cout<<"\n";
        }else if (index==lastIndex-1){
            std::cout<<"No element found after entered element\n";
            std::cout<<"\n";
        }else if (index==lastIndex-2){
            lastIndex--;
        }else{
            int count = index;
            while (count<lastIndex-2){
                s[count+1] = s[count+2];
                count++;
            }
            lastIndex--;
        }
    }
}

void deleteBefore(){
    if (startIndex==-1){
        cout<<"Empty\n";
    }else if (lastIndex==0){
        cout<<"Only 1 element found and deleted\n";
        startIndex = lastIndex = -1;
    }else{
        int id;
        cout<<"Enter id after which to be inserted: ";
        cin>>id;
        std::cout<<"\n";
        int index = search(s, id);
        if (index==-1){
            cout<<"Id not found\n";
            cout<<"\n";
        }else if (index==startIndex){
            cout<<"No element found before entered element\n";
            cout<<"\n";
        }else if (index==startIndex+1){
            startIndex++;
        }else{
            int count = index;
            while (count>=startIndex+2){
                s[count-1] = s[count-2];
                count--;
            }
            startIndex++;
        }
    }
}

void deleteSpecific(){
    if (startIndex==-1){
        cout<<"Empty\n";
    }else if (lastIndex==0){
        cout<<"Only 1 element found and deleted\n";
        startIndex = lastIndex = -1;
    }else{
        int id;
        cout<<"Enter id after which to be inserted: ";
        cin>>id;
        cout<<"\n";
        int index = search(s, id);
        if (index==-1){
            cout<<"Id not found\n";
        }else{
            int count = index;
            while (count<lastIndex-1){
                s[count] = s[count+1];
                count++;
            }
            lastIndex--;
        }
    }
}
