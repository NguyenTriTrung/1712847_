#include<stdio.h>
#include<conio.h>
#include<io.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<wchar.h>
// struct sinh vien
struct SV {
	wchar_t MSSV[11];
	wchar_t Ten[31];
	wchar_t Khoa[50];
	wchar_t gmail[50];
	wchar_t Namvaohoc[5];
	wchar_t NamSinh[11];
	wchar_t Hinhanh[16];
	wchar_t Motabanthan[1001];
	wchar_t Sothich1[101];
};
wchar_t** TaoMangThongTin(FILE *f, int &n)
{
	n = 0;
	wchar_t **a = (wchar_t**)malloc(1 * sizeof(wchar_t*));
	while (!feof(f))
	{
		a[n] = (wchar_t*)malloc(1500 * sizeof(wchar_t));
		fgetws(a[n], 1400, f);
			n++;
			a = (wchar_t**)realloc(a, (n + 1) * sizeof(wchar_t*));
	
	}

	return a;
}
void Chuyen(wchar_t *&b, wchar_t a[])
{
	int k = wcslen(b);
	for (int i = 0;i<k;i++)
		a[i] = b[i];

	a[k] = '\0';
}
SV* laythongtin(wchar_t a[])
{
	SV* sv = (SV*)malloc(sizeof(SV));
	int numb = 0;
	wchar_t *p;
	p = wcstok(a, L",");
	while (p != NULL)
	{
		if (numb == 0)
			Chuyen(p, sv->MSSV);
		if (numb == 1)
			Chuyen(p, sv->Ten);
		if (numb == 2)
			Chuyen(p, sv->Khoa);
		if (numb == 3)
			Chuyen(p, sv->Namvaohoc);
		if (numb == 4)
			Chuyen(p, sv->NamSinh);
		if (numb == 5)
			Chuyen(p, sv->Hinhanh);
		if (numb == 6)
			Chuyen(p, sv->Motabanthan);
		if (numb == 7)
			Chuyen(p, sv->Sothich1);
		if (numb == 8)
			Chuyen(p, sv->gmail);

		p = wcstok(NULL, L","); //cat chuoi tu vi tri dung lai truoc do
		numb++;
	}

	return sv;
}
void GhiFile(wchar_t *b, SV *sv)
{
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);
	FILE* p = _wfopen(b, L"w,ccs=UTF-16LE");
	fwprintf(p, L"%s\n", L"<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n");
	fwprintf(p, L"%s\n", L"<html xmlns=\"http://www.w3.org/1999/xhtml\">\n");
	fwprintf(p, L"%s\n", L"	<head>\n");
	fwprintf(p, L"%s\n", L"		<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />\n");
	fwprintf(p, L"		<link rel=\"stylesheet\" type=\"text/css\" href=\"personal.css\" />\n");
	fwprintf(p, L"		<title>HCMUS - %ls</title>\n", sv->Ten);
	fwprintf(p, L"%s\n", L"	</head>\n");
	fwprintf(p, L"%s\n", L"		<div class=\"Layout_container\">\n");
	fwprintf(p, L"%s\n", L"			<!-- Begin Layout Banner Region -->\n");
	fwprintf(p, L"%s\n", L"			<div class=\"Layout_Banner\" >\n");
	fwprintf(p, L"%s\n", L"				<div><img id=\"logo\" src=\"Images/logo.jpg\" height=\"105\" /></div>\n");
	fwprintf(p, L"%s\n", L"				<div class=\"Header_Title\">TRUONG ÐAI HOC KHOA HOC TỰ NHIÊN</div>\n");
	fwprintf(p, L"%s\n", L"			</div>\n");
	fwprintf(p, L"%s\n", L"			<!-- End Layout Banner Region -->\n");
	fwprintf(p, L"%s\n", L"			<!-- Begin Layout MainContents Region -->\n");
	fwprintf(p, L"%s\n", L"			<div class=\"Layout_MainContents\">\n");
	fwprintf(p, L"%s\n", L"				<!-- Begin Below Banner Region -->\n");
	fwprintf(p, L"%s\n", L"				<div class=\"Personal_Main_Information\">\n");
	fwprintf(p, L"%s\n", L"					<!-- Begin Thông tin cá nhân của sinh viên ------------------------------------------------------------------------------------------->\n");
	fwprintf(p, L"%s\n", L"					<div class=\"Personal_Location\"> \n");
	fwprintf(p, L"%s\n", L"						<img src=\"Images/LogoFooter.jpg\" width=\"27\" height=\"33\" />\n");
	fwprintf(p, L"						<span class=\"Personal_FullName\">%ls - %ls</span>\n", sv->Ten, sv->MSSV);
	fwprintf(p, L"%s\n", L"						<div class=\"Personal_Department\">KHOA CÔNG NGHỆ THÔNG TIN</div>\n");
	fwprintf(p, L"%s\n", L"						<br />\n");
	fwprintf(p, L"%s\n", L"						<div class=\"Personal_Phone\">\n");
	fwprintf(p, L"%s\n", L"						</div>\n");
	fwprintf(p, L"%s\n", L"						<br />\n");
	fwprintf(p, L"%s\n", L"						<br />\n");
	fwprintf(p, L"%s\n", L"					</div>\n");
	fwprintf(p, L"%s\n", L"					<!-- End Thông tin cá nhân của sinh viên ------------------------------------------------------------------------------------------->\n");
	fwprintf(p, L"%s\n", L"					<div class=\"Personal_HinhcanhanKhung\">\n");
	fwprintf(p, L"						<img src=\"Images/%ls\" class=\"Personal_Hinhcanhan\" />\n", sv->Hinhanh);
	fwprintf(p, L"%s\n", L"					</div>\n");
	fwprintf(p, L"%s\n", L"				</div>\n");
	fwprintf(p, L"%s\n", L"				<!-- End Below Banner Region -->\n");
	fwprintf(p, L"%s\n", L"				<!-- Begin MainContents Region -->\n");
	fwprintf(p, L"%s\n", L"				<div class=\"MainContain\">\n");
	fwprintf(p, L"%s\n", L"\n");
	fwprintf(p, L"%s\n", L"					<!-- Begin Top Region -->\n");
	fwprintf(p, L"%s\n", L"					<div class=\"MainContain_Top\">\n");
	fwprintf(p, L"%s\n", L"\n");
	fwprintf(p, L"%s\n", L"						<div class=\"InfoGroup\">Thông tin cá nhân</div>\n");
	fwprintf(p, L"%s\n", L"                       <div>\n");
	fwprintf(p, L"%s\n", L"                            <ul class=\"TextInList\">\n");
	fwprintf(p, L"<li>Họ và tên: %ls </li>\n<li>MSSV:%ls </li>", sv->Ten, sv->MSSV);
	fwprintf(p, L"								 <li>Sinh viên khoa %ls </li>\n", sv->Khoa);
	fwprintf(p, L"								 <li>Sinh Gmail: %ls </li>\n", sv->gmail);
	fwprintf(p, L"								 <li>Ngày sinh: %ls </li>\n", sv->NamSinh);
	fwprintf(p, L"								 <li>Sinh viên khoa %s </li>\n", sv->Namvaohoc);
	fwprintf(p, L"							 </ul>\n");
	fwprintf(p, L"%s\n", L"						</div>\n");
	fwprintf(p, L"%s\n", L"                       <div class=\"InfoGroup\">Sở thích</div>\n");
	fwprintf(p, L"%s\n", L"                       <div>\n");
	fwprintf(p, L"%s\n", L"                            <ul class=\"TextInList\">\n");
	fwprintf(p, L"                              <li>%ls</li>\n", sv->Sothich1);

	fwprintf(p, L"%s\n", L"							 </ul>\n");
	fwprintf(p, L"%s\n", L"						</div>\n");
	fwprintf(p, L"%s\n", L"						<div class=\"InfoGroup\">Mô tả</div>\n");
	fwprintf(p, L"%s\n", L"						<div class=\"Description\">\n");
	fwprintf(p, L"                            %ls\n", sv->Motabanthan);
	fwprintf(p, L"%s\n", L"						</div>\n");
	fwprintf(p, L"%s\n", L"\n");
	fwprintf(p, L"%s\n", L"					</div>\n");
	fwprintf(p, L"%s\n", L"				</div>\n");
	fwprintf(p, L"%s\n", L"			</div>\n");
	fwprintf(p, L"%s\n", L"\n");
	fwprintf(p, L"%s\n", L"			<!-- Begin Layout Footer -->\n");
	fwprintf(p, L"%s\n", L"			<div class=\"Layout_Footer\">\n");
	fwprintf(p, L"%s\n", L"				<div class=\"divCopyright\">\n");
	fwprintf(p, L"%s\n", L"					<br />\n");
	fwprintf(p, L"%s\n", L"					<img src=\"Images/LogoFooter_gray.jpg\" width=\"34\" height=\"41\" /><br />\n");
	fwprintf(p, L"%s\n", L"					<br />\n");
	fwprintf(p, L"%s\n", L"				@2018</br>\n");
	fwprintf(p, L"%s\n", L"				Ðồ án giữa kì</br>\n");
	fwprintf(p, L"%s\n", L"				kĩ thuật lâp trình</br>\n");
	fwprintf(p, L"%s\n", L"				TH2018/03</br>\n");
	fwprintf(p, L"%s\n", L"				1712847 - Nguyễn Trí Trung</br>\n");
	fwprintf(p, L"%s\n", L"				</div>\n");
	fwprintf(p, L"%s\n", L"			</div>\n");
	fwprintf(p, L"%s\n", L"			<!-- End Layout Footer -->\n");
	fwprintf(p, L"%s\n", L"		</div>\n");
	fwprintf(p, L"%s\n", L"	</body>\n");
	fwprintf(p, L"%s\n", L"</html>");
	fclose(p);

}
wchar_t* ten_file(wchar_t *s1)
{
	int a = wcslen(s1);
	wchar_t *s = new wchar_t[a + 6];
	for (wint_t i = 0; i < a; i++)
	{
		s[i] = s1[i];
	}
	s[a] = L'.';
	s[a + 1] = L'h';
	s[a + 2] = L't';
	s[a + 3] = L'm';
	s[a + 4] = L'l';
	s[a + 5] = L'\0';

	return s;
}
void main()
{
	int n;
	FILE* fo = _wfopen(L"File.csv", L"rt,ccs=UTF-16LE");
	if (fo == NULL)
	{
		printf("Mo tap tin that bai\n");
		system("pause");
		exit(0);
	}

	wchar_t **a = TaoMangThongTin(fo, n);

	for (int i = 0;i<n;i++)
	{
		SV *p = laythongtin(a[i]);
		wchar_t *filename;
		filename = (wchar_t*)malloc(30 * sizeof(wchar_t));
		filename = ten_file(p->MSSV);
		GhiFile(filename, p);
	}

	free(a);
	//	getch();
	system("pause");
}