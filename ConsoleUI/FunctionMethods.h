#pragma once
#include <thread>
#include "SlideMenu.h"
#include "Database.h"
#include "DauSach.h"
#include "MuonTra.h"
#include "DocGia.h"

using namespace std;

void ShowMainScreen();
void SetupConsole();
void FormClosing(LIST_DOCGIA listDG, LIST_DAUSACH listDS, bool isSaveFile);
int* SelectionFuntion(int rootLine = -1, int childLine = -1);
void QuanLiDocGia(LIST_DOCGIA& listDS, MYPOINT location);
void InDanhSachDG(LIST_DOCGIA listDG);
void InDanhSachQuaHan(LIST_DAUSACH listDS, LIST_DOCGIA lstDG);
void HienThiDauSach(LIST_DAUSACH& listDS, MYPOINT location);
void CapNhatDauSach(LIST_DAUSACH& listDS, MYPOINT location);
void CapNhatDanhMucSach(LIST_DAUSACH& listDS);
void TimSach(LIST_DAUSACH& listDS, MYPOINT location);
void MuonTraSach(LIST_DOCGIA& listDG, LIST_DAUSACH& listDS, MYPOINT location);
void InDSDauSachMuonNhieuNhat(LIST_DAUSACH& listDS, MYPOINT location);