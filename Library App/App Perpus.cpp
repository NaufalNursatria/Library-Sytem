#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

struct buku{
	char judul[128];
	char tajuk[4];
	char peminjam[64];
    char date[11];
	int id;
	int id1;
	int hari;
	struct buku *left, *right;
}*root=NULL,*root1=NULL;

//informasi buku
struct buku *databuku(){
	struct buku *bukubaru =(struct buku*)malloc(sizeof(struct buku));
	int i;
	printf("Masukan Judul Buku: ");
	scanf(" %[^\n]s",&bukubaru->judul);
	printf("Masukan Tajuk Buku (max 3 huruf): ");
	scanf("%s",&bukubaru->tajuk);
	system("CLS");
    bukubaru->id = 0;
    for(i = 0; i < strlen(bukubaru->judul); i++)
        bukubaru->id += (int)bukubaru->judul[i];
	return bukubaru;
};

struct buku *id(struct buku *newbook){
	struct buku *temp =  (struct buku*)malloc(sizeof(struct buku));
	temp = newbook;
	temp->left = temp->right = NULL;
	printf("Buku berhasil didaftarkan\n");
	printf("\nId\t\tJudul Buku\tTajuk\n");
	printf("\n%d\t\t%s\t\t%s\n\n", temp->id, temp->judul, temp->tajuk);
	system("PAUSE");
	system("CLS");
	return temp;
}

struct buku *id1(struct buku *newbook){
	struct buku *temp =  (struct buku*)malloc(sizeof(struct buku));
	temp = newbook;
	temp->left = temp->right = NULL;
	system("PAUSE");
	system("CLS");
	return temp;
}

//proses insert buku ke bst
struct buku *insert(struct buku *listbuku, struct buku *newbook){
	if (listbuku == NULL){
		return id(newbook);
	}
	else if (newbook->id < listbuku->id){
		listbuku->left = insert(listbuku->left, newbook);
	}
	else if (newbook->id > listbuku->id){
		listbuku->right = insert(listbuku->right, newbook);
	}
	return listbuku;
}

struct buku *insert1(struct buku *listbuku, struct buku *newbook){
	if (listbuku == NULL){
		return id1(newbook);
	}
	else if (newbook->id1 < listbuku->id1){
		listbuku->left = insert(listbuku->left, newbook);
	}
	else if (newbook->id1 > listbuku->id1){
		listbuku->right = insert(listbuku->right, newbook);
	}
	return listbuku;
}

//searching buku di bst
int search(struct buku *book, int entry){
	if (book!=NULL){
		if (entry != book->id){
			if(entry < book->id){
				search(book->left, entry);
			}
			else if(entry > book->id){
				search(book->right, entry);
			}	
		}
		else if (entry == book->id){
			printf("\nId\t\tJudul Buku\tTajuk\n");
			printf("\n%d\t\t%s\t\t%s\n\n", book->id, book->judul, book->tajuk);
			return 1;		
		}
	}
	else if (book == NULL){
		return 0;
	}
}

int search2(struct buku *book, int entry){
	if (book!=NULL){
		if (entry != book->id){
			if(entry < book->id){
				search(book->left, entry);
			}
			else if(entry > book->id){
				search(book->right, entry);
			}	
		}
		else if (entry == book->id){
			return 1;		
		}
	}
	else if (book == NULL){
		return 0;
	}
}

//print semua buku di bst
void inorder(struct buku *root){ 
    if (root != NULL){ 
        inorder(root->left); 
		printf("\n%d\t\t%s\t\t%s\n\n", root->id, root->judul, root->tajuk);  
        inorder(root->right); 
    } 
}

void inorder1(struct buku *root){ 
    if (root != NULL){ 
        inorder(root->left); 
		printf("\n%d\t\t%s\t\t%s\t%s\t\t%s\n\n", root->id, root->judul, root->tajuk,root->peminjam,root->date);  
        inorder(root->right); 
    } 
} 

//proses pemindahan buku dari bst ke bst lain
struct buku *moveData(struct buku* root, int xid){
    struct buku *temp1 = (struct buku*)malloc(sizeof(struct buku));
    char xDate[11];
	char xPeminjam[64];
    char xJudul[128];
    char xTajuk[4];
    if (root->id == xid){
        temp1->id = root->id;
        strncpy(xJudul, root->judul, sizeof(xJudul));        
        strncpy (temp1->judul, xJudul, sizeof(temp1->judul));
        strncpy(xTajuk, root->tajuk, sizeof(xTajuk));        
        strncpy (temp1->tajuk, xTajuk, sizeof(temp1->tajuk));
        printf("Nama Peminjam: ");
        scanf(" %[^\n]s", &temp1->peminjam);
        printf("Masukkan Tanggal Peminjaman(DD/MM/YYYY): ");
		scanf (" %[^\n]s", &temp1->date);
		printf("Lama Peminjaman(jumlah hari): ");
		scanf ("%d", &temp1->hari);
        return temp1;
    }
    if (root->left != NULL){
		if (root->id > xid){ 
        	moveData(root->left, xid); 
    	} 
    }
    if (root->right != NULL){
        if (root->id < xid){ 
        	moveData(root->right, xid); 
    	} 	
	}	
}

struct buku *moveData1(struct buku* root, int xid){
    struct buku *temp1 = (struct buku*)malloc(sizeof(struct buku));
    int x;
    char xJudul[128];
    char xTajuk[4];
    if (root->id == xid){
        temp1->id = root->id;
        strncpy(xJudul, root->judul, sizeof(xJudul));        
        strncpy (temp1->judul, xJudul, sizeof(temp1->judul));
        strncpy(xTajuk, root->tajuk, sizeof(xTajuk));        
        strncpy (temp1->tajuk, xTajuk, sizeof(temp1->tajuk));
        return temp1;
    }
    if (root->left != NULL){
		if (root->id > xid){ 
        	moveData(root->left, xid); 
    	} 
    }
    if (root->right != NULL){
        if (root->id < xid){ 
        	moveData(root->right, xid); 
    	} 	
	}	
}

struct buku * minValuebuku(struct buku* buku){ 
    struct buku* current = buku; 
    while (current && current->left != NULL){
        current = current->left;
    }
    return current; 
} 

//delete buku dari bst
struct buku* deletebuku(struct buku* root, int xid){
    if (root == NULL){
		return root;
	}
    if (xid < root->id){
        root->left = deletebuku(root->left, xid); 
	}
    else if (xid > root->id){
        root->right = deletebuku(root->right, xid);
    }
    else{ 
        if (root->left == NULL) 
        { 
            struct buku *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct buku *temp = root->left; 
            free(root); 
            return temp; 
        }
        struct buku* temp = minValuebuku(root->right); 
        root->id = temp->id;
        root->right = deletebuku(root->right, temp->id); 
    } 
    return root; 
} 

int main(){
	int pilihan;
	struct buku *newBook;
	struct buku *root = NULL;
	struct buku *root1 = NULL;
	struct buku *temp;
	do{
		printf("Aplikasi Perpustakaan \nMenu \n 1.Daftar Buku \n 2.Cari Buku \n 3.Meminjam Buku \n 4.Pengembalian Buku \n 5.Lihat Koleksi \n 6.Exit");
		printf("\nMasukkan pilihan anda : ");
		scanf("%d",&pilihan);
		system("CLS");
		if (pilihan == 1){
			newBook = databuku();
			root = insert(root, newBook);
			getch();
		}
		else if (pilihan == 2){
			char n[128];
			int i,angka;
			printf("Masukan judul buku: ");
			scanf(" %[^\n]s",&n);
			angka = 0;
    		for(i = 0; i < strlen(n); i++){
        		angka += (int)n[i];
        	}
        	if (search(root, angka) == 1){
				printf("Buku ditemukan\n");
				system("PAUSE");
				system("CLS");
			}
			else {
				printf("Buku tidak ditemukan\n");
				system("PAUSE");
				system("CLS");
			}
			getch();	
		}
		else if (pilihan == 3){
			struct buku *data;
			int angka;
			printf("\nId\t\tJudul Buku\tTajuk\n");
			inorder(root);
			printf("Masukan ID buku yang akan dipinjam: ");
			scanf("%d", &angka);
			if (search2(root, angka) == 1){
                data = moveData(root, angka);
                if (root1!=NULL){
                    insert1(root1, data);
                }
                else{
                    root1 = insert1(root1, data);
                }
                root = deletebuku(root, angka);
				system("CLS");
            }
            else{
                printf("Buku tidak tersedia\n");
                system("PAUSE");
				system("CLS");
            }
		}
		else if (pilihan == 4){
			struct buku *data;
			int angka,x;
			printf("\nId\t\tJudul Buku\tTajuk\tNama Peminjam\tTanggal Dipinjam\n");
			inorder1(root1);
			printf("Masukan ID buku yang akan dikembalikan: ");
			scanf("%d", &angka);
			if (search2(root1, angka) == 1){
				x = root1->hari*1000;
        		printf("Total Biaya Pinjam(dalam Rupiah): %d\n",x);
                data = moveData1(root1, angka);
                if (root!=NULL){
                    insert1(root, data);
                }
                else{
                    root = insert1(root, data);
                }
                root1 = deletebuku(root1, angka);
				system("CLS");
            }
            else{
                printf("Buku tidak tersedia");
                system("PAUSE");
				system("CLS");
            }
		}
		else if (pilihan == 5){
			printf("\nId\t\tJudul Buku\tTajuk\n");
			inorder(root);
			system("PAUSE");
			system("CLS");
		}
		else{
			break;
		}
	}
	while (pilihan != 6);
}
