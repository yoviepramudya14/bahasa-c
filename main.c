
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
void menu();
void tambah_penumpang();
void tampil_penumpang();
void edit_penumpang();
void hapus_penumpang();
void cari_penumpang();
void close();
void header();

struct DATA {
	char nama[30];
	int umur,id;
	char jk[30];
	float nilai[5];
	int total;

}tambah,cek,hapus,sort[100],temp;

char index[2];
struct date{
	int tgl;
	int bln;
	int thn;
};
int main()
{
	system("cls");
		printf("Now Loading");
		Sleep(500);
		printf(". ");
		Sleep(500);
		printf(". ");
		Sleep(500);
		printf(". ");
		Sleep(500);
		printf(". ");
		Sleep(500);
		printf(". ");
	menu();
	return 0;
}
void menu(){
	int pilih;
	menu:
		system("cls");
		header();
		printf("MAIN MENU ::");
		printf("\n[1]. Tambah Penumpang Unsyiahairlines");
		printf("\n[2]. Tampil Data Penumpang");
		printf("\n[3]. Cari Penumpang");
		printf("\n[4]. Hapus Data Penumpang");
		printf("\n[5]. Edit Data Penumpang");
		printf("\n[6]. Keluar");
		printf("\n\nInput Pilihan Nomor Menu : ");
		scanf("%d", &pilih);
		switch(pilih){
			case 1:tambah_penumpang();
				break;
			case 2:tampil_penumpang();
				break;
			case 3: cari_penumpang();
				break;
			case 4:hapus_penumpang();
				break;
			case 5:edit_penumpang();
				break;
			case 6:close();
				break;
			default:printf("\nMohon Maaf Pilihan Anda Salah !");
				getche();
				goto menu;
		}
}
void tambah_penumpang(){
	FILE *ptr,*ptr1;
	int count=0;

	ptr =fopen("penumpang.txt","a");
		system("cls");
		ptr1 =fopen("penumpang.txt","r");
		while (fscanf (ptr1,"%d;%[^;];%[^;];%d;%f;%f;%f;%f;%f\n",&tambah.id,tambah.nama,tambah.jk,&tambah.umur,&tambah.nilai[0],&tambah.nilai[1],&tambah.nilai[2],&tambah.nilai[3],&tambah.nilai[4])!=EOF)
		{
			tambah.id++;
		}
		cek.id = tambah.id;
		fclose(ptr1);
		printf ("masukan nama penumpang : ");fflush(stdin);
		scanf ("%[^\n]",tambah.nama);
		printf ("masukan JK penumpang : ");fflush(stdin);
		scanf ("%[^\n]",tambah.jk);
		printf ("masukan umur penumpang : ");fflush(stdin);
		scanf ("%d",&tambah.umur);
		printf("id_pesawat\t: ");
		scanf("%f",&tambah.nilai[0]);
		printf("id_case kargo\t: ");
		scanf("%f",&tambah.nilai[1]);
		printf("id_cek in\t: ");
		scanf("%f",&tambah.nilai[2]);
		printf("id_billing\t: ");
		scanf("%f",&tambah.nilai[3]);
		tambah.nilai[4]=(tambah.nilai[0]+tambah.nilai[1]+tambah.nilai[2]+tambah.nilai[3])/4;
		tambah.total = tambah.nilai[4];
		fprintf(ptr,"%d;%s;%s;%d;%f;%f;%f;%f;%f\n",tambah.id,tambah.nama,tambah.jk,tambah.umur,tambah.nilai[0],tambah.nilai[1],tambah.nilai[2],tambah.nilai[3],tambah.nilai[4]);
		fclose(ptr);

		printf("\n\nData penumpang Sudah Disimpan !");
		add_invalid:
		printf("\n\n\tEnter 1 untuk menu utama dan 0 untuk keluar : ");
		switch(getch()){
    		case '1': menu();
        		break;
        	case '0': close();
        		break;
        	default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto add_invalid;
 		}
}

void close(){
}
void tampil_penumpang()
{
	FILE *view;
	view = fopen("penumpang.txt","r");
	int test=0;
	system ("cls");
	printf("+------+---------------------------+---------+---------+-------------+---------+------------+------------+--------+\n");
	printf("|  ID  |            NAMA           |   JK    |   UMUR  |   pesawat   |  cargo  |   cek in   |   billing  |  final |\n");
	printf("+------+---------------------------+---------+---------+-------------+---------+------------+------------+--------+\n");
	while (fscanf (view,"%d;%[^;];%[^;];%d;%f;%f;%f;%f;%f\n",&tambah.id,tambah.nama,tambah.jk,&tambah.umur,&tambah.nilai[0],&tambah.nilai[1],&tambah.nilai[2],&tambah.nilai[3],&tambah.nilai[4])!=EOF)
	{
    printf("| %3d  |  %-23s  |  %4s   | %6d  | %-11.2f | %-6.2f  | %8.2f   |  %8.2f  | %5.2f  |\n",tambah.id,tambah.nama,tambah.jk,tambah.umur,tambah.nilai[0],tambah.nilai[1],tambah.nilai[2],tambah.nilai[3],tambah.nilai[4]);
		test++;
	printf("+------+---------------------------+---------+---------+-------------+---------+------------+------------+--------+\n")	;
	}
	printf ("\nJumlah Data penumpang : %d",test);
	fclose(view);

	if(test==0)
	{
		system("cls");
		printf ("\nData Kosong ! \n");
	}
	list_invalid:
    printf("\n\nEnter 1 untuk menu utama dan 0 untuk keluar : ");
    switch(getch()){
    	case '1': menu();
        	break;
        case '0': close();
        	break;
        default:printf("\nMaaf Kesalahan Input !");
        	getche();
        	goto list_invalid;
 	}
}
void cari_penumpang()
{
	FILE *ptr;
	int test=0;
	system("cls");
	ptr=fopen("penumpang.txt","r");
	system("cls");
	printf("Input ID penumpang : ");
	scanf("%d", &cek.id);
	while(fscanf (ptr,"%d;%[^;];%[^;];%d;%f;%f;%f;%f;%f\n",&tambah.id,tambah.nama,tambah.jk,&tambah.umur,&tambah.nilai[0],&tambah.nilai[1],&tambah.nilai[2],&tambah.nilai[3],&tambah.nilai[4])!=EOF){
		if(tambah.id==cek.id){
			test=1;

			printf ("\nID [%d]",tambah.id);
			printf("\nNama Penumpang\t: %s",tambah.nama);
			printf("\nJenis Kelamin\t: %s",tambah.jk);
			printf("\nUmur\t\t: %d",tambah.umur);
			printf("\nPesawat\t: %.2f",tambah.nilai[0]);
			printf("\ncargo\t: %.2f",tambah.nilai[1]);
			printf("\ncek in\t: %.2f",tambah.nilai[2]);
			printf("\nbiling\t: %.2f",tambah.nilai[3]);
			printf("\nHarga tiket\t: %.2f",tambah.nilai[4]);
			printf("\nPASTIKAN ANDA MEMBELI TIKET DARI TEMPAT TERPERCAYA");
		}
	}
	fclose(ptr);
	if(test!=1){
		system("cls");
		detail_print:
		printf("\nData tidak ditemukan !\a\a\a");
		detail_invalid:
		printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama dan 2 untuk keluar :");
        switch(getch()){
            case '0': cari_penumpang();
            	break;
            case '1': menu();
            	break;
            case '2': close();
            	break;
            default:printf("\nMaaf Kesalahan Input !");
            	getche();
            	goto detail_invalid;
        }
	}else{
		detail_valid:
		printf("\n\n\nInput 1 untuk ke menu utama dan 0 untuk keluar :");
        switch(getch()){
        	case '1': menu();
       			break;
       		case '0': close();
       			break;
       		default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto detail_valid;
       	}
    }

}
void header(){
	printf("====SELAMAT DATANG DI PENERBANGAN UNSYIAHAIRLINE====");
	time_t mytime;
	time(&mytime);
	printf("\n%s", ctime(&mytime));
	 char username[10]= "iya", pass[10]= "aku";
   char usr[10], pas[10];
   int status = 0, salah = 0;

   while(status < 3){
      printf("Masukkan Username : ");
      gets(usr);
      printf("Masukkan Password : ");
      gets(pas);

      if(strcmp(username, username)==0 && strcmp (pass, pass)== 0){
         printf("Akses diterima. \n");
         printf("SELAMAT DATANG DI ANGKASAPURA II \n") ;
         break;
      }else{
         printf("Username dan Password tidak match\n");
         salah++;
         if(salah == 3){
            printf("Akses ditolak\n");
         }
      }
      status++;
   }

   system("pause");
   return 0;


}
void hapus_penumpang()
{
	FILE *lama, *baru;
	int test=0;
	lama = fopen("penumpang.txt","r");
	baru = fopen("baru.txt","w");
	system("cls");
	printf("Input No. ID penumpang yang akan di hapus : ");
	scanf("%d", &hapus.id);
	while(fscanf (lama,"%d;%[^;];%[^;];%d;%f;%f;%f;%f;%f\n",&tambah.id,tambah.nama,tambah.jk,&tambah.umur,&tambah.nilai[0],&tambah.nilai[1],&tambah.nilai[2],&tambah.nilai[3],&tambah.nilai[4])!=EOF)
	{
		if(tambah.id != hapus.id)
		{
			fprintf(baru,"%d;%s;%s;%d;%f;%f;%f;%f;%f\n",tambah.id,tambah.nama,tambah.jk,tambah.umur,tambah.nilai[0],tambah.nilai[1],tambah.nilai[2],tambah.nilai[3],tambah.nilai[4]);
		}
		else{
			test++;
			printf("\nData Penumpang No ID : %d dengan Nama : %s\n",tambah.id,tambah.nama);
			printf("\nBerhasil dihapus dari Daftar !");
		}
	}
	fclose(lama);
	fclose(baru);
	remove("penumpang.txt");
	rename("baru.txt","penumpang.txt");
		if(test==0){
            printf("\nData tidak ditemukan !\a\a\a");
            erase_invalid:
            printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama and 2 untuk keluar :");
			switch(getch()){
            	case '0': hapus_penumpang();
            		break;
            	case '1': menu();
            		break;
            	case '2': close();
            		break;
            	default:printf("\nMaaf Kesalahan Input !");
            		getche();
            		goto erase_invalid;
			}
    }
    else{
    	erase_valid:
		printf("\nInput 1 untuk ke menu utama and 0 untuk keluar :");
        switch(getch()){
       		case '1': menu();
       			break;
       		case '0': close();
       			break;
       		default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto erase_valid;
        }
    }

}
void edit_penumpang()
{
	int pilih,test=0;
	FILE *lama,*baru;
	lama = fopen("penumpang.txt","r");
	baru = fopen ("baru.txt","w");
	system("cls");

	printf ("Masukan ID penumpang : ");
	scanf ("%d",&cek.id);
	while(fscanf (lama,"%d;%[^;];%[^;];%d;%f;%f;%f;%f;%f\n",&tambah.id,tambah.nama,tambah.jk,&tambah.umur,&tambah.nilai[0],&tambah.nilai[1],&tambah.nilai[2],&tambah.nilai[3],&tambah.nilai[4])!=EOF)
	{
		if(tambah.id == cek.id)
		{
			test=1;
			ganti:
				printf("\nNo. ID : %d dimiliki Penumpang dengan Nama : %s",tambah.id,tambah.nama);
				printf("\n\nData yang akan diganti : ");
				printf("\n[1]. Nama");
				printf("\n[2]. Jenis Kelamin");
				printf("\n[3]. Umur");
				printf("\nInput Pilihan : ");
				scanf("%d",&pilih);

				if(pilih == 1)
				{
					printf ("\nMasukan Data Nama Baru : ");fflush(stdin);
					scanf ("%[^\n]",cek.nama);
					strcpy(tambah.nama,cek.nama);
						fprintf(baru,"%d;%s;%s;%d;%f;%f;%f;%f;%f\n",tambah.id,tambah.nama,tambah.jk,tambah.umur,tambah.nilai[0],tambah.nilai[1],tambah.nilai[2],tambah.nilai[3],tambah.nilai[4]);
					printf ("\nPerubahan Sudah Disimpan !");
				}
				else if (pilih == 2)
				{
					printf("\nMasukan Data Jenis Kelamin L/P : ");fflush(stdin);
					scanf ("%[^\n]",cek.jk);
					strcpy(tambah.jk,cek.jk);
						fprintf(baru,"%d;%s;%s;%d;%f;%f;%f;%f;%f\n",tambah.id,tambah.nama,tambah.jk,tambah.umur,tambah.nilai[0],tambah.nilai[1],tambah.nilai[2],tambah.nilai[3],tambah.nilai[4]);
					printf ("\nPerubahan Sudah Disimpan !");
				}
				else if (pilih == 3)
				{
					printf ("\nMasukan Data Umur Baru : ");
					scanf ("%d",&cek.umur);
					tambah.umur = cek.umur;
					fprintf(baru,"%d;%s;%s;%d;%f;%f;%f;%f;%f\n",tambah.id,tambah.nama,tambah.jk,tambah.umur,tambah.nilai[0],tambah.nilai[1],tambah.nilai[2],tambah.nilai[3],tambah.nilai[4]);
					printf ("\nPerubahan Sudah Disimpan !");
				}
				else{
					printf("\n\nInput Anda Salah !");
					getche();
					goto ganti;
				}
		}
		else
		{
			fprintf(baru,"%d;%s;%s;%d;%f;%f;%f;%f;%f\n",tambah.id,tambah.nama,tambah.jk,tambah.umur,tambah.nilai[0],tambah.nilai[1],tambah.nilai[2],tambah.nilai[3],tambah.nilai[4]);
		}
	}

	fclose(lama);
	fclose(baru);
	remove("penumpang.txt");
	rename("baru.txt","penumpang.txt");
	if(test!=1){
		system("cls");
        printf("\nData tidak ditemukan !\a\a\a");
        edit_invalid:
        printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama dan 2 untuk keluar :");
        switch(getch()){
            case '0': edit_penumpang();
            	break;
            case '1': menu();
            	break;
            case '2': close();
            	break;
            default:printf("\nMaaf Kesalahan Input !");
            	getche();
            	goto edit_invalid;
        }
    }
    else{
    	edit_valid:
		printf("\n\n\nInput 1 untuk ke menu utama dan 0 untuk keluar :");
        switch(getch()){
        	case '1': menu();
        		break;
        	case '0': close();
        		break;
        	default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto edit_valid;
        }
    }
}
