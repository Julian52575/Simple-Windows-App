
#include "my.hpp"
extern HWND hWnd;                                      // the Window

LPITEMIDLIST open_folder(char* path)
{
	if (!path)
		path = (char *) "C:\\";

	TCHAR szDir[MAX_PATH];
	BROWSEINFO bInfo = { 0 };
	bInfo.hwndOwner = hWnd;
	bInfo.pidlRoot = NULL;
	bInfo.pszDisplayName = szDir; // Address of a buffer to receive the display name of the folder selected by the user
	bInfo.lpszTitle = L"Please, select a folder"; // Title of the dialog
	bInfo.ulFlags = 0;
	bInfo.lpfn = NULL;
	bInfo.lParam = 0;
	bInfo.iImage = -1;

	LPITEMIDLIST lpItem = SHBrowseForFolder(&bInfo);
	return lpItem;
}