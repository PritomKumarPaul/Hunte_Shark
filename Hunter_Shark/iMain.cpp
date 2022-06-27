#include "iGraphics.h"
/*#include <cstdlib>
#include <ctime>*/
#include <cstring>


//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
int indsw, indsb, indsp, indmp, indmb, indmw,indms,indt;
int image1, image2, image3, background[5], BACKGROUND, option=0,gamestate=-1,gameover=0, bg[2],size=1,fs,goimage,congoimage,opbackground;
double movex = 0, movey = 0,sr[3],sl[3],ssx=410,ssy=270,nx=410,ny=270,move=0,nextx,nexty,tx,ty,s1=0,s2=0;
int b1 = 80, b2 = 60, w1 = 10, w2 = -10, h1 = 10, h2 = -10, shows = 0, fsy, ww1 = 20, ww2 = -20, wb1 = 15, wb2 = -15, hw1 = 20, hw2 = -20, hb1 = 15, hb2 = -15;
int curtime = 130, fletpre = 0, paused = 0, pausepic;
char pname[30];
int t1 = 151, t2 = 600 - 100;
int pw = 3, pb = 2, pp = 1, pointw = 15, pointb = 10, pointp = 5, cpoint = 0, tpoint = 0, fb, fp, fw;
int whale[10], showw[10] = { 0, 0 }, movexw[10] = { 0, 0 }, swx[10] = { 0, 0 }, cswx[10] = { 0, 0 }, swy[10] = { 0, 0 }, nw = 2, mtw[10] = { 0, 0 }, dis[10] = { 0, 0 }, dir[10] = { 0, 0 };
int Pompano[10], showp[10] = { 0, 0 }, movexp[10] = { 0, 0 }, spx[10] = { 0, 0 }, cspx[10] = { 0, 0 }, spy[10] = { 0, 0 }, np = 10, mtp[10] = { 0, 0 }, disp[10] = { 0, 0 }, dirp[10] = { 0, 0 };
int Barracuda[10], showb[10] = { 0, 0 }, movexb[10] = { 0, 0 }, sbx[10] = { 0, 0 }, csbx[10] = { 0, 0 }, sby[10] = { 0, 0 }, nb = 2, mtb[10] = { 0, 0 }, disb[10] = { 0, 0 }, dirb[10] = { 0, 0 };
int cw[10] = { 0, 0 }, cb[10] = { 0, 0 }, cp[10] = { 0, 0 };
double tm;
int optionpic;
int congoshower=0;
int namecollected = 0;
int previous[2], next[2], leaderboard, chrunch, chrunchshower = 0, namenext = 0,highprev=0,gp,gph,gu,guh,gpshower=0,gushower=1,gps,gus;
int ng[2], lg[2], lb[2], inst[2], ex[2],sel[5];
int save1[2], save2[2], save3[2], save4[2], save5[2];
int selsave[5] = { 0, 0 }, savestate = 0, loadstate = 0, alsa[5] = { 0, 0 }, notsaved = 1, notsavedimage;
int pausedbg;
int selected, sselected, gobuffer = -1, boxh = 0, eaten = 0, savebuffer = 0, sbpressed, loaded = 0, timetick = 0;
int mainmenumusic = 1, gameplaymusic = 1, crunchmusic = 1, sizeupmusic = 1;
struct leaderboard{
	char player_name[30];
	int t_score=0;
};

//b[selected].lshoww[i] = showw[i];
//b[selected].lw1 = w1;

struct leaderboard a[5];
struct loadgame
{
	int lb1 , lb2 , lw1 , lw2 , lh1 , lh2 , lshows, lfsy, lww1, lww2, lwb1, lwb2, lhw1, lhw2, lhb1, lhb2;
	int lmovex, lmovey, lssx , lssy , lnx , lny , lmove , lnextx, lnexty, ltx, lty, ls1 , ls2 ;
	int lt1 , lt2 ,lsize;
	int lpw , lpb , lpp , lcpoint , ltpoint , lfb, lfp, lfw;
	int lwhale[10], lshoww[10] , lmovexw[10] , lswx[10] , lcswx[10] , lswy[10] , lnw , lmtw[10] , ldis[10] , ldir[10] ;
	int lPompano[10], lshowp[10] , lmovexp[10] , lspx[10] , lcspx[10] , lspy[10] , lnp , lmtp[10] , ldisp[10] , ldirp[10] ;
	int lBarracuda[10], lshowb[10] , lmovexb[10] , lsbx[10] , lcsbx[10] , lsby[10] , lnb , lmtb[10] , ldisb[10] , ldirb[10] ;
	int lcw[10], lcb[10], lcp[10], ltimetick ,lcurtime;
};
struct loadgame b[5];
void timei()
{
	if (gamestate == 1 && eaten != 1)
	{
		curtime++;
	}
}
void checkscore()
{
	int i = 4,changed=0, temp,flag=1;
	char cname[30];
	if (namecollected == 0)
	{
		FILE *fip;
		//char name[30];
		int score;
		fip = fopen("pointstable.txt", "r");
		for (i = 0; i<5; i++)
		{
			for (int i = 0; i < 5; i++)
			{
				fscanf(fip, "%[^\n]%d\n", a[i].player_name, &a[i].t_score);
				fflush(stdin);
				//;
				fflush(stdin);
			}
		}
		fclose(fip);
	}
	
	
	if (a[4].t_score < tpoint)
	{
		a[4].t_score = tpoint;
		strcpy(a[4].player_name, pname);
		fflush(stdin);
		congoshower = 1;
		changed = 1;
	}
	for (i = 4; i >= 1; i--)
	{
		if (a[i].t_score>a[i - 1].t_score)
		{
			temp = a[i - 1].t_score;
			a[i - 1].t_score = a[i].t_score;
			a[i].t_score = temp;
			strcpy(cname, a[i - 1].player_name);
			strcpy(a[i - 1].player_name, a[i].player_name);
			strcpy(a[i].player_name, cname);
		}
		else
			break;
	}
		FILE *sip = fopen("pointstable.txt", "w");
		for (i = 0; i<5; i++)
		{
			
				fprintf(sip, "%s\n%d\n", a[i].player_name, a[i].t_score);
				fflush(stdin);
				//a[i].t_score = score;
				//fflush(stdin);
			
		}
		fclose(sip);

	tpoint = 0;
}
void pointshow()
{
	printf("current point:%d", cpoint);
}
void spawnw()
{
	if (size == 1)
	{
		nw = 2;
	}
	else if (size == 2)
	{
		nw = 3;
	}
	if (size == 3)
	{
		nw = 5;
	}
	if (gamestate == 1)
	{
		for (int i = 0; i < nw; i++)
		{
			if (showw[i] == 0)
			{
				showw[i] = 1;
				mtw[i] = 0;
				int sdirw = rand() % 2;
				if (sdirw == 1)
				{

					swy[i] = rand() % 450;
					swx[i] = 880;//900 - 160;
					whale[i] = iLoadImage("OrcaIdle2.png");
					fw = 0;
					//whale[i] = iLoadImage("Killer_Whale _02.png");
					cswx[i] = swx[i];
				}
				else
				{
					swy[i] = rand() % 450;
					swx[i] = -140;
					whale[i] = iLoadImage("OrcaIdle1.png");
					fw = 1;
					//whale[i] = iLoadImage("Killer_Whale _01.png");
					cswx[i] = swx[i];
				}
				break;
			}
		}
	}
}
void gamesaver()
{
	for (int i = 0; i<10; i++)
	{
		b[selected].lshoww[i] = showw[i];
		b[selected].lmovexw[i] = movexw[i];
		b[selected].lswx[i] = swx[i];
		b[selected].lcswx[i] = cswx[i];
		b[selected].lswy[i] = swy[i];
		b[selected].lmtw[i] = mtw[i];
		b[selected].ldis[i] = dis[i];
		b[selected].ldir[i] = dir[i];
		b[selected].lshowp[i] = showp[i];
		b[selected].lmovexp[i] = movexp[i];
		b[selected].lspx[i] = spx[i];
		b[selected].lcspx[i] = cspx[i];
		b[selected].lspy[i] = spy[i];
		b[selected].lmtp[i] = mtp[i];
		b[selected].ldisp[i] = disp[i];
		b[selected].ldirp[i] = dirp[i];
		b[selected].lshowb[i] = showb[i];
		b[selected].lmovexb[i] = movexb[i];
		b[selected].lsbx[i] = sbx[i];
		b[selected].lcsbx[i] = csbx[i];
		b[selected].lsby[i] = sby[i];
		b[selected].lmtb[i] = mtb[i];
		b[selected].ldisb[i] = disb[i];
		b[selected].ldirb[i] = dirb[i];
		b[selected].lcw[i] = cw[i];
		b[selected].lcp[i] = cp[i];
		b[selected].lcb[i] = cb[i];
		b[selected].lwhale[i] = cb[i];
		b[selected].lPompano[i] = cb[i];
		b[selected].lBarracuda[i] = cb[i];
	}
	b[selected].lsize = size;
	b[selected].lcurtime = curtime;
	b[selected].ltimetick = timetick;
	b[selected].lb1 = b1;
	b[selected].lb2 = b2;
	b[selected].lw1 = w1;
	b[selected].lw2 = w2;
	b[selected].lh1 = h1;
	b[selected].lh2 = h2;
	b[selected].lshows = shows;
	b[selected].lfsy = fsy;
	b[selected].lww1 = ww1;
	b[selected].lww2 = ww2;
	b[selected].lwb1 = wb1;
	b[selected].lwb2 = wb2;
	b[selected].lhw1 = hw1;
	b[selected].lhw2 = hw2;
	b[selected].lhb1 = hb1;
	b[selected].lhb2 = hb2;
	b[selected].lmovex = movex;
	b[selected].lmovey = movey;
	b[selected].lssx = ssx;
	b[selected].lssy = ssy;
	b[selected].lnx = nx;
	b[selected].lny = ny;
	b[selected].lmove = move;
	b[selected].lnextx = nextx;
	b[selected].lnexty = nexty;
	b[selected].ltx = tx;
	b[selected].lty = ty;
	b[selected].ls1 = s1;
	b[selected].ls2 = s2;
	b[selected].lt1 = t1;
	b[selected].lt2 = t2;
	b[selected].lpw = pw;
	b[selected].lpb = pb;
	b[selected].lpp = pp;
	b[selected].lcpoint = cpoint;
	b[selected].ltpoint = tpoint;
	b[selected].lfb = fb;
	b[selected].lfp = fp;
	b[selected].lfw = fw;
}

void gameloader()
{
	for (int i = 0; i<10; i++)
	{
		showw[i] = b[selected].lshoww[i];
		movexw[i] = b[selected].lmovexw[i];
		swx[i] = b[selected].lswx[i];
		cswx[i] = b[selected].lcswx[i];
		swy[i] = b[selected].lswy[i];
		mtw[i] = b[selected].lmtw[i];
		dis[i] = b[selected].ldis[i];
		dir[i] = b[selected].ldir[i];
		showp[i] = b[selected].lshowp[i];
		movexp[i] = b[selected].lmovexp[i];
		spx[i] = b[selected].lspx[i];
		cspx[i] = b[selected].lcspx[i];
		spy[i] = b[selected].lspy[i];
		mtp[i] = b[selected].lmtp[i];
		disp[i] = b[selected].ldisp[i];
		dirp[i] = b[selected].ldirp[i];
		showb[i] = b[selected].lshowb[i];
		movexb[i] = b[selected].lmovexb[i];
		sbx[i] = b[selected].lsbx[i];
		csbx[i] = b[selected].lcsbx[i];
		sby[i] = b[selected].lsby[i];
		mtb[i] = b[selected].lmtb[i];
		disb[i] = b[selected].ldisb[i];
		dirb[i] = b[selected].ldirb[i];
		cw[i] = b[selected].lcw[i];
		cp[i] = b[selected].lcp[i];
		cb[i] = b[selected].lcb[i];
		whale[i] = b[selected].lcb[i];
		Pompano[i] = b[selected].lcb[i];
		Barracuda[i] = b[selected].lcb[i];
	}
	size = b[selected].lsize;
	curtime = b[selected].lcurtime;
	timetick = b[selected].ltimetick;
	b1 = b[selected].lb1;
	b2 = b[selected].lb2;
	w1 = b[selected].lw1;
	w2 = b[selected].lw2;
	h1 = b[selected].lh1;
	h2 = b[selected].lh2;
	shows = b[selected].lshows;
	fsy = b[selected].lfsy;
	ww1 = b[selected].lww1;
	ww2 = b[selected].lww2;
	wb1 = b[selected].lwb1;
	wb2 = b[selected].lwb2;
	hw1 = b[selected].lhw1;
	hw2 = b[selected].lhw2;
	hb1 = b[selected].lhb1;
	hb2 = b[selected].lhb2;
	movex = b[selected].lmovex;
	movey = b[selected].lmovey;
	ssx = b[selected].lssx;
	ssy = b[selected].lssy;
	nx = b[selected].lnx;
	ny = b[selected].lny;
	move = b[selected].lmove;
	nextx = b[selected].lnextx;
	nexty = b[selected].lnexty;
	tx = b[selected].ltx;
	ty = b[selected].lty;
	s1 = b[selected].ls1;
	s2 = b[selected].ls2;
	t1 = b[selected].lt1;
	t2 = b[selected].lt2;
	pw = b[selected].lpw;
	pb = b[selected].lpb;
	pp = b[selected].lpp;
	cpoint = b[selected].lcpoint;
	tpoint = b[selected].ltpoint;
	fb = b[selected].lfb;
	fp = b[selected].lfp;
	fw = b[selected].lfw;
	/*if (fw == 1)
	{
		whale[i] = iLoadImage("OrcaIdle1.png");
	}
	else
		whale[i] = iLoadImage("OrcaIdle2.png");
	if (fw == 1)
	{
		whale[i] = iLoadImage("OrcaIdle1.png");
	}
	else
		whale[i] = iLoadImage("OrcaIdle2.png");
	if (fw == 1)
	{
		whale[i] = iLoadImage("OrcaIdle1.png");
	}
	else
		whale[i] = iLoadImage("OrcaIdle2.png");*/

}
void movew()
{
	for (int i = 0; i < 5; i++)
	{
		if (showw[i] == 1 && mtw[i] == 0)
		{
			mtw[i] = 1;
			dis[i] = (rand() % 10) * 5;
			dir[i] = rand() % 2;
			if (dir[i] == 1 && cswx[i] != 900 - 160 && cw[i] != 0)
			{
				whale[i] = iLoadImage("OrcaIdle1.png");
				fw = 1;
				//whale[i] = iLoadImage("Killer_Whale _01.png"); 
				dis[i] = dis[i] * 1;
				movexw[i] = movexw[i] + 5;
				dis[i] = dis[i] - movexw[i];
				cswx[i] = swx[i] + movexw[i];
			}
			else if (dir[i] == 0 && cswx[i] != 0 && cw[i] != 0)
			{
				whale[i] = iLoadImage("OrcaIdle2.png");
				fw = 0;
				//whale[i] = iLoadImage("Killer_Whale _02.png");
				dis[i] = dis[i] * (-1);
				movexw[i] = movexw[i] - 5;
				dis[i] = dis[i] + movexw[i];
				cswx[i] = swx[i] + movexw[i];
			}
		}
		else if (showw[i] == 1 && mtw[i] == 1)
		{
			if ((cswx[i] < 0 && cw[i] == 0) || (cswx[i] > 900 - 160 && cw[i] == 0))
			{
				
				if (cswx[i]<0)
				{
					movexw[i] = movexw[i] + 5;
					if (loaded != 0)
					{
						whale[i] = iLoadImage("OrcaIdle1.png");
						loaded--;
					}
					cswx[i] = swx[i] + movexw[i];
					if (cswx[i] == 0)
					{
						mtw[i] = 0;
						cw[i] = 1;
					}
				}
				else if (cswx[i]>900 - 160)
				{
					movexw[i] = movexw[i] - 5;
					if (loaded != 0)
					{
						whale[i] = iLoadImage("OrcaIdle2.png");
						loaded--;
					}
					cswx[i] = swx[i] + movexw[i];
					if (cswx[i] == 900 - 160)
					{
						mtw[i] = 0;
						cw[i] = 1;
					}
					
				}
			}
			else if (cswx[i] != 900 - 160 && dir[i] == 1 && dis[i] != 0)
			{
				movexw[i] = movexw[i] + 5;
				cswx[i] = swx[i] + movexw[i];
				dis[i] = dis[i] - movexw[i];
				if (loaded != 0)
				{
					whale[i] = iLoadImage("OrcaIdle1.png");
					loaded--;
				}
			}
			else if (cswx[i] != 0 && dir[i] == 0 && dis[i] != 0)
			{
				movexw[i] = movexw[i] - 5;
				dis[i] = dis[i] + movexw[i];
				cswx[i] = swx[i] + movexw[i];
				if (loaded != 0)
				{
					whale[i] = iLoadImage("OrcaIdle2.png");
					loaded--;
				}
			}
			
			else if (dis[i] == 0 || cswx[i] == 0 || cswx[i] == 900 - 160)
			{
				mtw[i] = 0;
				if (cswx[i] == 0)
				{
					whale[i] = iLoadImage("OrcaIdle1.png");
					fw = 1;
					//whale[i] = iLoadImage("Killer_Whale _01.png");
				}
				else if (cswx[i] == 900 - 160)
				{
					whale[i] = iLoadImage("OrcaIdle2.png");
					fw = 0;
					//whale[i] = iLoadImage("Killer_Whale _02.png");
				}
			}
		}
	}
}

void spawnp()
{
	if (gamestate == 1)
	{
		for (int i = 0; i < 10; i++)
		{
			if (showp[i] == 0)
			{
				showp[i] = 1;
				mtp[i] = 0;
				int posp = rand() % 2;
				if (posp == 1)
				{
					spy[i] = rand() % 520;
					spx[i] = 900 - 10;
					Pompano[i] = iLoadImage("Pompano2.png");
					cspx[i] = spx[i];
				}
				else
				{
					spy[i] = rand() % 520;
					spx[i] = -60;
					Pompano[i] = iLoadImage("Pompano1.png");
					cspx[i] = spx[i];
				}
				break;
			}
		}
	}
}

void movep()
{
	for (int i = 0; i < 10; i++)
	{
		if (showp[i] == 1 && mtp[i] == 0)
		{
			mtp[i] = 1;
			disp[i] = (rand() % 10) * 5;
			dirp[i] = rand() % 2;
			if (dirp[i] == 1 && cspx[i] != 900 - 70 && cp[i] != 0)
			{
				Pompano[i] = iLoadImage("Pompano1.png");
				disp[i] = disp[i] * 1;
				movexp[i] = movexp[i] + 5;
				disp[i] = disp[i] - movexp[i];
				cspx[i] = spx[i] + movexp[i];
			}
			else if (dirp[i] == 0 && cspx[i] != 0 && cp[i] != 0)
			{
				Pompano[i] = iLoadImage("Pompano2.png");
				disp[i] = disp[i] * (-1);
				movexp[i] = movexp[i] - 5;
				disp[i] = disp[i] + movexp[i];
				cspx[i] = spx[i] + movexp[i];
			}
		}
		else if (showp[i] == 1 && mtp[i] == 1)
		{
			if ((cspx[i] < 0 && cp[i] == 0) || (cspx[i] > 900 - 160 && cp[i] == 0))
			{
				
				if (cspx[i]<0)
				{
					movexp[i] = movexp[i] + 5;
					if (loaded != 0)
					{
						Pompano[i] = iLoadImage("Pompano1.png");
						loaded--;
					}
					cspx[i] = spx[i] + movexp[i]; 
					if (cspx[i] == 0)
					{
						mtp[i] = 0;
						cp[i] = 1;
					}
				}
				else if (cspx[i]>900 - 160)
				{
					movexp[i] = movexp[i] - 5;
					if (loaded != 0)
					{
						Pompano[i] = iLoadImage("Pompano2.png");
						loaded--;
					}
					
					cspx[i] = spx[i] + movexp[i];
					if (cspx[i] == 900 - 160)
					{
						mtp[i] = 0;
						cp[i] = 1;
					}
				}
			}
			else if (cspx[i] != 900 - 70 && dirp[i] == 1 && disp[i] != 0)
			{
				movexp[i] = movexp[i] + 5;
				if (loaded != 0)
				{
					Pompano[i] = iLoadImage("Pompano1.png");
					loaded--;
				}
				cspx[i] = spx[i] + movexp[i];
				disp[i] = disp[i] - movexp[i];
			}
			else if (cspx[i] != 0 && dirp[i] == 0 && disp[i] != 0)
			{
				movexp[i] = movexp[i] - 5;
				if (loaded != 0)
				{
					Pompano[i] = iLoadImage("Pompano2.png");
					loaded--;
				}
				disp[i] = disp[i] + movexp[i];
				cspx[i] = spx[i] + movexp[i];
			}
			
			else if (disp[i] == 0 || cspx[i] == 0 || cspx[i] == 900 - 70)
			{
				mtp[i] = 0;
				if (cspx[i] == 0)
				{
					Pompano[i] = iLoadImage("Pompano1.png");
				}
				else if (cspx[i] == 900 - 70)
				{
					Pompano[i] = iLoadImage("Pompano2.png");
				}
			}
		}
	}
}

void spawnb()
{
	if (size == 1)
	{
		nb = 4;
	}
	else if (size == 2)
	{
		nb = 6;
	}
	if (size == 3)
	{
		nb = 8;
	}
	if (gamestate == 1)
	{
		for (int i = 0; i < nb; i++)
		{
			if (showb[i] == 0)
			{
				showb[i] = 1;
				mtb[i] = 0;
				int posb = rand() % 2;
				if (posb == 1)
				{

					sby[i] = rand() % 500;
					sbx[i] = 900 - 10;
					Barracuda[i] = iLoadImage("Barracuda2.png");
					fb = 0;
					csbx[i] = sbx[i];
				}
				else
				{
					sby[i] = rand() % 500;
					sbx[i] = -90;
					Barracuda[i] = iLoadImage("Barracuda1.png");
					fb = 1;
					csbx[i] = sbx[i];
				}
				break;
			}
		}
	}
}

void moveb()
{
	for (int i = 0; i < nb; i++)
	{
		if (showb[i] == 1 && mtb[i] == 0 )
		{
			mtb[i] = 1;
			disb[i] = (rand() % 10) * 5;
			dirb[i] = rand() % 2;
			if (dirb[i] == 1 && csbx[i] != 900 - 110 && cb[i] != 0)
			{
				Barracuda[i] = iLoadImage("Barracuda1.png");
				fb = 1;
				//whale[i] = iLoadImage("Killer_Whale _01.png"); 
				disb[i] = disb[i] * 1;
				movexb[i] = movexb[i] + 5;
				disb[i] = disb[i] - movexb[i];
				csbx[i] = sbx[i] + movexb[i];
			}
			else if (dirb[i] == 0 && csbx[i] != 0 && cb[i] != 0 && cb[i] != 0)
			{
				Barracuda[i] = iLoadImage("Barracuda2.png");
				fb = 0;
				disb[i] = disb[i] * (-1);
				movexb[i] = movexb[i] - 5;
				disb[i] = disb[i] + movexb[i];
				csbx[i] = sbx[i] + movexb[i];
			}
		}
		else if (showb[i] == 1 && mtb[i] == 1)
		{
			if ((csbx[i] < 0 && cb[i] == 0) || (csbx[i] > 900 - 160 && cb[i] == 0))
			{
				if (csbx[i]<0)
				{
					movexb[i] = movexb[i] + 5;
					csbx[i] = sbx[i] + movexb[i];
					if (loaded != 0)
					{
						Barracuda[i] = iLoadImage("Barracuda1.png");
						loaded--;
					}
					if (csbx[i] == 0)
					{
						mtb[i] = 0;
						cb[i] = 1;
					}
				}
				else if (csbx[i]>900 - 160)
				{
					movexb[i] = movexb[i] - 5;
					csbx[i] = sbx[i] + movexb[i];

					if (loaded != 0)
					{
						Barracuda[i] = iLoadImage("Barracuda2.png");
						loaded --;
					}
					if (csbx[i] == 900 - 160)
					{
						mtb[i] = 0;
						cb[i] = 1;
					}
				}
			}
			else if (csbx[i] != 900 - 110 && dirb[i] == 1 && disb[i] != 0)
			{
				movexb[i] = movexb[i] + 5;
				if (loaded != 0)
				{
					Barracuda[i] = iLoadImage("Barracuda1.png");
					loaded--;
				}
				csbx[i] = sbx[i] + movexb[i];
				disb[i] = disb[i] - movexb[i];
			}
			else if (csbx[i] != 0 && dirb[i] == 0 && disb[i] != 0)
			{
				movexb[i] = movexb[i] - 5;
				if (loaded != 0)
				{
					Barracuda[i] = iLoadImage("Barracuda2.png");
					loaded--;
				}
				
				disb[i] = disb[i] + movexb[i];
				csbx[i] = sbx[i] + movexb[i];
			}
			else if (disb[i] == 0 || csbx[i] == 0 || csbx[i] == 900 - 110)
			{
				
				mtb[i] = 0;
				if (csbx[i] == 0)
				{
					Barracuda[i] = iLoadImage("Barracuda1.png");
					fb = 1;
				}
				else if (csbx[i] == 900 - 110)
				{
					Barracuda[i] = iLoadImage("Barracuda2.png");
					fb = 0;
				}
			}
		}
	}
}

void sew()
{
	for (int i = 0; i < 10; i++)
	{
		if (size >= pw && showw[i]!=0 && fs == 1 && (nx + 170 +w2 >= cswx[i]+w1 && nx + 170 +w2 <= cswx[i] + 160+w2))
		{
			for (int j = ny+h1; j <= ny + 130+h2; j++)
			{
				if (j >= swy[i] + h1 && j <= swy[i] + 120 + h2)
				{
					showw[i] = 0;
					movexw[i] = 0;
					cpoint += pointw;
					//PlaySound("Bite sound", NULL, SND_ASYNC);
					chrunchshower = 10;
					cw[i] = 0;
					break;
				}
			}
		}
		else if (size >= pw && showw[i] != 0 && fs == 0 && (nx + w1 >= cswx[i] + w2 && nx + w1 <= cswx[i] + 160 + w2))
		{
			for (int j = ny + h1; j <= ny + 130+ h2; j++)
			{
				if (j>= swy[i] + h1 && j<= swy[i] + 120 +h2)
				{
					showw[i] = 0;
					movexw[i] = 0;
					cpoint += pointw;
					//PlaySound("Bite sound", NULL, SND_ASYNC);
					chrunchshower = 10;
					cw[i] = 0;
					break;
				}
			}
		}
	}
}

void wes()
{
	for (int i = 0; i < 10; i++)
	{
		if (size < pw && fw == 1 && (cswx[i] + 160 +ww2>= nx+ww1 && cswx[i] + 160 +ww2<= nx + b1 +ww2))
		{
			for (int j = swy[i]+hw1; j <= swy[i] + 120+hw2; j++)
			{
				if (j >= ny+hw1 && j <= ny + b2+hw2)
				{
					eaten = 1;
					gobuffer = 0;
					tpoint += cpoint;
					//checkscore();
					//cpoint = 0;
					size = 1;
					b1 = 80;
					b2 = 60;
					//chrunchshower = 1;
					movex = 0;
					movey = 0;
					shows = 0;
					
				}
			}
		}
		if (size < pw && fw == 0 && (cswx[i] + ww1 >= nx + ww2 && cswx[i] + ww1 <= nx + b1 + ww1))
		{
			for (int j = swy[i]+hw1; j <= swy[i] + 120+hw2; j++)
			{
				if (j >= ny+hw1 && j <= ny + b2 +hw2)
				{
					eaten = 1;
					gobuffer = 0;
					tpoint += cpoint;
					//cpoint = 0;
					//checkscore();
					size = 1;
					b1 = 80;
					b2 = 60;
					movex = 0;
					//chrunchshower = 1;
					movey = 0;
					shows = 0;
					
				}
			}
		}
	}
}

void seb()
{
	for (int i = 0; i < 10; i++)
	{
		if (size >= pb && showb[i] != 0 && fs == 1 && (nx + b1 + w2 >= csbx[i] + w1 && nx + b1 + w2 <= csbx[i] + 110 + w2))
		{
			for (int j = ny+h1; j <= ny + b2+h2; j++)
			{
				if (j >= sby[i]+h1 && j <= sby[i] + 68+h2)
				{
					showb[i] = 0;
					movexb[i] = 0;
					cpoint += pointb;
					//PlaySound("Bite sound", NULL, SND_ASYNC);
					chrunchshower = 10;
					cb[i] = 0;
					if (size == 2 && cpoint >= 800)
					{
						size = 3;
						b1 = 170;
						b2 = 130;
						size = 3;
						ssx = 365;
						ssy = 235;
					}
					break;
				}
			}
		}
		else if (size >= pb && showb[i] != 0 && fs == 0 && (nx + w1 >= csbx[i] + w2 && nx + w1 <= csbx[i] + 110 + w1))
		{
			for (int j = ny+h1; j <= ny + b2+h2; j++)
			{
				if (j >= sby[i]+h1 && j <= sby[i] + 68+h2)
				{
					showb[i] = 0;
					movexb[i] = 0;
					cpoint += pointb;
					//PlaySound("Bite sound", NULL, SND_ASYNC);
					chrunchshower = 10;
					cb[i] = 0;
					if (size == 2 && cpoint >= 800)
					{
						size = 3;
						b1 = 170;
						b2 = 130;
						size = 3;
						ssx = 365;
						ssy = 235;
					}
					break;
				}
			}
		}
	}
}

void bes()
{
	for (int i = 0; i < 10; i++)
	{
		if (size < pb && fb == 1 && (csbx[i] + 110 +wb2>= nx+wb1 && csbx[i] + 110 +wb2<= nx + wb2))
		{
			for (int j = sby[i]+hb1; j <= sby[i]+hb2 + 68; j++)
			{
				if (j >= ny+hb1 && j <= ny + b2+hb2)
				{
					eaten = 1;
					gobuffer = 0;
					tpoint += cpoint;
					//cpoint = 0;
					//checkscore();
					size = 1;
					b1 = 80;
					b2 = 60;
					movex = 0;
					movey = 0;
					shows = 0;
					//chrunchshower = 1;
					
				}
			}
		}
		if (size < pb && fb == 0 && (csbx[i] +wb1>= nx+wb2 && csbx[i] +wb1<= nx + b1+wb1))
		{
			for (int j = sby[i]+hb1; j <= sby[i] + 68+hb2; j++)
			{
				if (j >= ny+hb1 && j <= ny + b2+hb2)
				{
					eaten = 1;
					gobuffer = 0;
					tpoint += cpoint;
					//cpoint = 0;
					//checkscore();
					size = 1;
					b1 = 80;
					b2 = 60;
					movex = 0;
					movey = 0;
					shows = 0;
					//chrunchshower = 1;
					
				}
			}
		}
	}
}

void sep()
{
	for (int i = 0; i < 10; i++)
	{
		if (fs == 1 && showp[i] != 0  && (nx + b1 + w2 >= cspx[i] + w1 && nx + b1 + w2 <= cspx[i] + 70 + w2))
		{
			for (int j = ny; j <= ny + b2; j++)
			{
				if (j >= spy[i] && j <= spy[i] + 50)
				{
					showp[i] = 0;
					movexp[i] = 0;
					//PlaySound("Bite sound", NULL, SND_ASYNC);
					cpoint += pointp;
					chrunchshower = 10;
					pointshow();
					cp[i] = 0;
					if (size == 1 && cpoint >= 100)
					{
						size = 2;
						ssx = 390;
						ssy = 260;
						b1 = 120;
						b2 = 80;
					}
					else if (size == 2 && cpoint >= 500)
					{
						size = 3;
						b1 = 170;
						b2 = 130;
						size = 3;
						ssx = 365;
						ssy = 235;
					}
					break;
				}
			}
		}
		else if (fs == 0 && showp[i] != 0 && (nx + w1 >= cspx[i] + w2 && nx + w1 <= cspx[i] + 70 + w1))
		{
			for (int j = ny ; j <= ny + b2 ; j++)
			{
				if (j >= spy[i] && j <= spy[i] + 50)
				{
					showp[i] = 0;
					movexp[i] = 0;
					//PlaySound("Bite sound", NULL, SND_ASYNC);
					cpoint += pointp;
					chrunchshower = 10;
					cp[i] = 0;
					pointshow();
					if (size == 1 && cpoint >= 100)
					{
						size = 2;
						ssx = 390;
						ssy = 260;
						b1 = 120;
						b2 = 80;
					}
					else if (size == 2 && cpoint >= 500)
					{
						size = 3;
						b1 = 170;
						b2 = 130;
						size = 3;
						ssx = 365;
						ssy = 235;
					}
					break;
				}
			}
		}
	}
}
void sharkmove()
{
	if (move == 1 && savestate==0)
	{
		if (fs == 1 && nextx - nx - (b1 / 2)> 3){

			movex = movex + (5 * tx / tm);
			nx = ssx + movex;
		}
		else if (fs == 0 && nx + (b1 / 2) - nextx> 3)
		{
			movex = movex + (5 * tx / tm);
			nx = ssx + movex;
		}
		else
			s1 = 0;
		if (fsy==0 && ny + (b2 / 2) - nexty > 3)
		{

			movey = movey + (5 * ty / tm);
			ny = ssy + movey;
		}
		else if (fsy == 1 && nexty - ny - (b2 / 2)> 3)
		{
			movey = movey + (5 * ty / tm);
			ny = 270 + movey;
		}
		else
			s2 = 0;
		if (s1 == 0 && s2 == 0)
			move = 0;

	}
}

void iDraw()
{
	iClear();
	if (gamestate == 8)
	{
		iShowImage(0, 0, 900, 600, gps);
		if (highprev == 0)
			iShowImage(750, 50, 100, 40, previous[0]);
		else
			iShowImage(758, 52, 87, 30, previous[1]);
	}
	else if (gamestate == 9)
	{
		iShowImage(0, 0, 900, 600, gus);
		if (highprev == 0)
			iShowImage(750, 50, 100, 40, previous[0]);
		else
			iShowImage(758, 52, 87, 30, previous[1]);
	}
	else if (gamestate == -1)
	{
		iShowImage(0, 0, 900, 600, bg[0]);
		if (namenext==0)
			iShowImage(650, 40, 160, 100, next[0]);
		else
			iShowImage(650-3, 40+11, 160+5, 75, next[1]);
		iFilledRectangle(70, 250, 270, 20);
		iFilledRectangle(50, 250, 20, 100);
		iFilledRectangle(70+270, 250, 10, 100);
		iFilledRectangle(70, 250+80, 270, 20);
		iSetColor(0, 0, 0);
		iFilledRectangle(370, 250, 460, 20);
		iFilledRectangle(350, 250, 20, 100);
		iFilledRectangle(370+460, 250, 20, 100);
		iFilledRectangle(370, 250+80, 460, 20);
		iText(90, 295, "enter your name(30 letters):", GLUT_BITMAP_HELVETICA_18);
		
		if (fletpre == 0)
		{
			iText(395, 295, " ");
		}
		else if (fletpre >= 1)
		{
			iText(395, 295, pname ,GLUT_BITMAP_HELVETICA_18);
		}
	}
	else if (gamestate == 0)
	{
		iShowImage(0, 0, 900, 600, bg[0]);
		checkscore();
		//iShowImage(200, 150, 500, 300, background[option]);
		if (sel[4] == 0)
		{
			iShowImage(350 , 142 , 200, 73, ex[0]);
		}
		if (sel[3] == 0)
		{
			iShowImage(350, 142 + 60 , 207, 73, inst[0]);
		}
		if (sel[2] == 0)
		{
			iShowImage(354, 145 + 120 , 194, 71, lb[0]);
		}
		if (sel[1] == 0)
		{
			iShowImage(355, 147 + 180 , 192, 67, lg[0]);
		}
		if (sel[0] == 0)
		{
			iShowImage(355, 143 + 240, 195, 73, ng[0]);
		}
		if (sel[4] == 1)
		{
			iShowImage(350, 142, 200, 73, ex[1]);
		}
		if (sel[3] == 1)
		{
			iShowImage(349, 140 + 60, 203, 82, inst[1]);
		}
		if (sel[2] == 1)
		{
			iShowImage(349, 141 + 120, 198+6, 74, lb[1]);
		}
		if (sel[1] == 1)
		{
			iShowImage(350-4, 141-3 + 180, 206, 75, lg[1]);
		}
		if (sel[0] == 1)
		{
			iShowImage(354, 147 + 240, 200-6, 66, ng[1]);
		}
	}
	else if (gamestate == 1)
	{
		/*if (move == 1)
			sharkmove();*/
		//iShowImage(0, 0, 900, 600, BACKGROUND);
		if (paused == 1)
		{
			iShowImage(0, 0, 900, 600, pausedbg);
			
		}
		else if (paused == 0)
		{
			iShowImage(0, 0, 900, 600, BACKGROUND);
		}
		if (savestate == 1 || savestate == 2 || loadstate == 1 || loadstate == 2)
		{
			iShowImage(0, 0, 900, 600, pausedbg);
		}
		if (gobuffer != 1500 && eaten == 1)
		{
			if (gobuffer < 100)
			{
				iSetColor(255, 255, 255);
				iText(200 + 140, 290, "S", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (gobuffer < 100)
			{
				iSetColor(255, 255, 255);
				iText(200 + 140, 290, "S", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (gobuffer < 300)
			{
				iSetColor(255, 255, 255);
				iText(200 + 140, 290, "SOR", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (gobuffer < 400)
			{
				iSetColor(255, 255, 255);
				iText(200 + 140, 290, "SORR", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (gobuffer < 500)
			{
				iSetColor(255, 255, 255);
				iText(200 + 140, 290, "SORRY ", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (gobuffer < 600)
			{
				iSetColor(255, 255, 255);
				iText(200 + 140, 290, "SORRY G", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (gobuffer < 700)
			{
				iSetColor(255, 255, 255);
				iText(200 + 140, 290, "SORRY GA", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (gobuffer < 800)
			{
				iSetColor(255, 255, 255);
				iText(200 + 140, 290, "SORRY GAM", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (gobuffer < 900)
			{
				iSetColor(255, 255, 255);
				iText(200 + 140, 290, "SORRY GAME", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (gobuffer < 1000)
			{
				iSetColor(255, 255, 255);
				iText(200 + 140, 290, "SORRY GAMEO", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (gobuffer < 1100)
			{
				iSetColor(255, 255, 255);
				iText(200 + 140, 290, "SORRY GAMEOV", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (gobuffer < 1200)
			{
				iSetColor(255, 255, 255);
				iText(200 + 140, 290, "SORRY GAMEOVE", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else if (gobuffer < 1500)
			{
				iSetColor(255, 255, 255);
				iText(200 + 140, 290, "SORRY GAMEOVER", GLUT_BITMAP_TIMES_ROMAN_24);
			}
			gobuffer += 5;
			iSetColor(0, 0, 0);
		}
		else if (gobuffer == 1500 && eaten == 1)
		{
			gamestate = 6;
			curtime = 0;
			eaten = 0;
			cpoint = 0;
			tpoint = 0;
			timetick = 0;
			for (int k = 0; k < 10; k++)
			{

				showw[k] = 0;
				movexw[k] = 0;
				swx[k] = 0;
				cswx[k] = 0;
				swy[k] = 0;
				mtw[k] = 0;
				dis[k] = 0;
				dir[k] = 0;
				showp[k] = 0;
				movexp[k] = 0;
				spx[k] = 0;
				cspx[k] = 0;
				spy[k] = 0;
				mtp[k] = 0;
				disp[k] = 0;
				dirp[k] = 0;
				showb[k] = 0;
				movexb[k] = 0;
				sbx[k] = 0;
				csbx[k] = 0;
				sby[k] = 0;
				mtb[k] = 0;
				disb[k] = 0;
				dirb[k] = 0;
				cw[k] = 0;
				cp[k] = 0;
				cb[k] = 0;
			}
		}
		if (size == 1 && shows == 1)
		{
			iShowImage(410 + movex, 270 + movey, b1, b2, sr[0]);//
			if (chrunchshower != 0 && fs == 1)
			{
				iShowImage(410 + movex + b1, 270 + movey, 60, 60, chrunch);
				chrunchshower--;
			}
			else if (chrunchshower != 0 && fs == 0)
			{
				iShowImage(410 + movex -60, 270 + movey, 60, 60, chrunch);
				chrunchshower--;
			}

		}
		else if (size == 2 && shows == 1)
		{
			iShowImage(390 + movex, 260 + movey, 120, 80, sr[0]);
			if (chrunchshower != 0 && fs == 1)
			{
				iShowImage(390 + movex + 120, 260 + movey, 60, 60, chrunch);
				chrunchshower--;
			}
			else if (chrunchshower != 0 && fs == 0)
			{
				iShowImage(390 + movex - 60, 260 + movey, 60, 60, chrunch);
				chrunchshower--;
			}
		}
		else if (size == 3 && shows == 1)
		{
			iShowImage(365 + movex, 235 + movey, 170, 130, sr[0]);
			if (chrunchshower != 0 && fs == 1)
			{
				iShowImage(365 + movex + 170, 235 + movey, 60, 60, chrunch);
				chrunchshower--;
			}
			else if (chrunchshower != 0 && fs == 0)
			{
				iShowImage(365 + movex - 60, 235 + movey, 60, 60, chrunch);
				chrunchshower--;
			}
		}
		for (int i = 0; i < nw; i++)
		{
			if (showw[i]!=0)
				iShowImage(cswx[i], swy[i], 160, 120, whale[i]);
		}
		for (int i = 0; i < 10; i++)
		{
			if (showp[i] != 0)
				iShowImage(cspx[i], spy[i], 70, 50, Pompano[i]);
		}
		for (int i = 0; i < nb; i++)
		{
			if (showb[i] != 0)
				iShowImage(csbx[i], sby[i], 110, 68, Barracuda[i]);
		}
		if (shows == 1)
		{
			sew();
			seb();
			sep();
			wes();
			bes();
		}

		int x,y;
		x = cpoint;
		char showingpoint[30];
		strcpy(showingpoint, "0000");
		for (int k = 3; ; k--)
		{
			y = x % 10;
			showingpoint[k] = y + 48;
			x = x / 10;
			if (x == 0)
				break;
		}
		iSetColor(0, 0, 0);
		iText(50, 580, "SCORE:", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(150, 580, showingpoint, GLUT_BITMAP_TIMES_ROMAN_24);
		char showtime[30];
		int m = (150 - curtime) / 60, s1 = ((150 - curtime) % 60) / 10, s2 = (150 - curtime) % 10;
		strcpy(showtime, "TIME LEFT : 00m 00s");
		showtime[17] = s2 + 48;
		showtime[16] = s1 + 48;
		showtime[13] = m + 48;
		if (150 - curtime <= 10)
		{
			if (timetick % 10 >= 5)
			{
				iSetColor(200, 0, 0);
				iText(480, 580, showtime, GLUT_BITMAP_TIMES_ROMAN_24);
			}
			//else if (timetick % 10 <= 4)
				//iText(480, 580, showtime, GLUT_BITMAP_TIMES_ROMAN_10);
			timetick++;
		}
		else
			iText(480, 580, showtime, GLUT_BITMAP_TIMES_ROMAN_24);
		if (paused == 1)
		{
			iShowImage(350, 250, 200, 100, pausepic);
		}
		if (loadstate == 2)
		{
			if (boxh<26)
				boxh += 2;
			iSetColor(121, 121, 163);
			iFilledRectangle(350, 270 - boxh, 200, 30);
			iFilledRectangle(350, 300 + boxh, 200, 30);
			iFilledRectangle(550, 270 - boxh, 30, 60 + boxh + boxh);
			iFilledRectangle(320, 270 - boxh, 30, 60 + boxh + boxh);
			iSetColor(118, 198, 204);

			iFilledRectangle(350, 300 - boxh, 199 + 1, 6 + boxh + boxh);

			if (boxh == 26)
			{
				iSetColor(121, 121, 163);
				iText(365, 300, "No saved game here", GLUT_BITMAP_HELVETICA_18);
				if (highprev == 0)
					iShowImage(750, 50, 100, 40, previous[0]);
				else
					iShowImage(758, 52, 87, 30, previous[1]);

			}
		}
		if (savestate == 2)
		{
			if (sbpressed == 1 && savebuffer != 0)
			{
				savebuffer--;
			}
			else if (sbpressed == 1 && savebuffer == 0)
			{
				sbpressed = 0;
				savestate = 0;
				iResumeTimer(indmb);
				iResumeTimer(indmp);
				iResumeTimer(indmw);
				iResumeTimer(indsp);
				iResumeTimer(indsw);
				iResumeTimer(indsb);
				iResumeTimer(indms);
				iResumeTimer(indt);
			}
			if (boxh<26)
				boxh += 2;
			iSetColor(121, 121, 163);
			iFilledRectangle(350, 270 - boxh, 200, 30);
			iFilledRectangle(350, 300 + boxh, 200, 30);
			iFilledRectangle(550, 270 - boxh, 30, 60 + boxh + boxh);
			iFilledRectangle(320, 270 - boxh, 30, 60 + boxh + boxh);
			iSetColor(118, 198, 204);
			
			iFilledRectangle(350, 300 - boxh, 199 + 1, 6 + boxh + boxh);
			
			if (boxh == 26)
			{
				iSetColor(121, 121, 163);
				iText(357, 300, "Your game was saved!", GLUT_BITMAP_HELVETICA_18);
				/*iFilledRectangle(420, 302-boxh, 60, 20);
				iSetColor(200, 200, 219);
				iText(435, 305-boxh, "OK", GLUT_BITMAP_HELVETICA_18);*/
				if (namenext == 0)
					iShowImage(650, 40, 160, 100, next[0]);
				else
					iShowImage(650 - 3, 40 + 11, 160 + 5, 75, next[1]);
				
			}
		}
		if (loadstate == 1)
		{
			if (highprev == 0)
				iShowImage(750, 50, 100, 40, previous[0]);
			else
				iShowImage(758, 52, 87, 30, previous[1]);
			if (selsave[4] == 0)
			{
				iShowImage(328, 121, 241, 73, save5[0]);
			}
			if (selsave[3] == 0)
			{
				iShowImage(334, 189, 232, 79, save4[0]);
			}
			if (selsave[2] == 0)
			{
				iShowImage(333, 262, 232, 71, save3[0]);
			}
			if (selsave[1] == 0)
			{
				iShowImage(324, 320, 254, 96, save2[0]);
			}
			if (selsave[0] == 0)
			{
				iShowImage(335, 143 + 251, 230, 85, save1[0]);
			}
			if (selsave[4] == 1)
			{
				iShowImage(350 - 26 + 8, 115, 213 + 24, 89, save5[1]);
			}
			if (selsave[3] == 1)
			{
				iShowImage(334, 191, 227, 80, save4[1]);
			}
			if (selsave[2] == 1)
			{
				iShowImage(331, 258, 238, 80, save3[1]);
			}
			if (selsave[1] == 1)
			{
				iShowImage(328, 334, 238, 70, save2[1]);
			}
			if (selsave[0] == 1)
			{
				iShowImage(326, 399, 247, 76, save1[1]);
			}
		}
		if (savestate == 1)
		{
			if (highprev == 0)
				iShowImage(750, 50, 100, 40, previous[0]);
			else
				iShowImage(758, 52, 87, 30, previous[1]);
			if (selsave[4] == 0)
			{
				iShowImage(328, 121, 241, 73, save5[0]);
			}
			if (selsave[3] == 0)
			{
				iShowImage(334, 189, 232, 79, save4[0]);
			}
			if (selsave[2] == 0)
			{
				iShowImage(333, 262, 232, 71, save3[0]);
			}
			if (selsave[1] == 0)
			{
				iShowImage(324, 320, 254, 96, save2[0]);
			}
			if (selsave[0] == 0)
			{
				iShowImage(335, 143 + 251, 230, 85, save1[0]);
			}
			if (selsave[4] == 1)
			{
				iShowImage(350 - 26 + 8, 115, 213 + 24, 89, save5[1]);
			}
			if (selsave[3] == 1)
			{
				iShowImage(334, 191, 227, 80, save4[1]);
			}
			if (selsave[2] == 1)
			{
				iShowImage(331, 258, 238, 80, save3[1]);
			}
			if (selsave[1] == 1)
			{
				iShowImage(328, 334, 238, 70, save2[1]);
			}
			if (selsave[0] == 1)
			{
				iShowImage(326, 399, 247, 76, save1[1]);
			}
		}
	}
	else if (gamestate == 6 || gamestate == 7)
	{
		iShowImage(0, 0, 900, 600, BACKGROUND);
		iShowImage(400, 250, 100, 100, goimage);
		if (namenext == 0)
			iShowImage(650, 40, 160, 100, next[0]);
		else
			iShowImage(650 - 3, 40 + 11, 160 + 5, 75, next[1]);
		//iShowImage(750, 50, 100, 40, next[0]);

		checkscore();
		tpoint = 0;
		if (congoshower == 1)
		{
			iShowImage(300, 400, 300, 150, congoimage);
			iText(230, 375, "Congratulations! Your name is on the leaderboards", GLUT_BITMAP_HELVETICA_18);
		}
	}
	else if (gamestate == 4)
	{
		iShowImage(0, 0, 900, 600, optionpic);
		if (gpshower == 1)
			iShowImage(400, 250, 100, 40, gph);
		else
			iShowImage(400, 250, 100, 40, gp);
		if (gushower == 1)
			iShowImage(400, 310, 100, 40, guh);
		else
			iShowImage(400, 310, 100, 40, gu);
		if (highprev == 0)
			iShowImage(750, 50, 100, 40, previous[0]);
		else
			iShowImage(758, 52, 87, 30, previous[1]);
	}
	else if (gamestate == 3)
	{
		t1 = 151; 
		t2 = 600 - 100;
		checkscore();
		char pos[] = "1";
		iShowImage(0, 0, 900, 600, BACKGROUND);
		iShowImage(300, 550, 300, 50, leaderboard);
		if (highprev == 0)
			iShowImage(750, 50, 100, 40, previous[0]);
		else
			iShowImage(758, 52, 87, 30, previous[1]);

		for (int i = 0; i < 5; i++)
		{
			int  x, y, num = 1;
			y = a[i].t_score;
			for (int j = 0; ; j++)
			{
				y = y / 10;
				if (y != 0)
				{
					num++;
				}
				else
					break;
			}
			//printf("%d\n", num);
			int tens = 1;
			for (int k = 1; k < num; k++)
			{
				tens = tens * 10;
			}
			fflush(stdin);
			y = a[i].t_score;
			char number[5];
			//char anumber[5];
			strcpy(number, "0");
			for (int k = 0; k < num; k++)
			{
				x = y / tens;
				number[k] = x + 48;
				y = y % tens;
				tens = tens / 10;
				printf("%c",number[k]);
			}
			number[num] = '\0';
			printf("\n");
			puts(number);
			printf("\n");
			//strcpy(anumber, number);
			iText(t1, t2, pos);
			t1 = t1 + 200;
			iText(t1, t2, a[i].player_name);
			t1 = t1 + 200;
			iText(t1, t2, number);
			t1 = 151;
			t2 = t2 - 50;
			pos[0]++;
		}
	}
	else if (gamestate == 2)
	{

		if (notsaved == 1)
		{
			iShowImage(0, 0, 900, 600, bg[0]);
			//iShowImage(300, 550, 300, 50, leaderboard);
			if (highprev == 0)
				iShowImage(750, 50, 100, 40, previous[0]);
			else
				iShowImage(758, 52, 87, 30, previous[1]);
			iShowImage(300, 200, 300, 200, notsavedimage);
		}
		else
		{
			iShowImage(0, 0, 900, 600, bg[0]);
			//iShowImage(300, 550, 300, 50, leaderboard);
			if (highprev == 0)
				iShowImage(750, 50, 100, 40, previous[0]);
			else
				iShowImage(758, 52, 87, 30, previous[1]);
			if (selsave[4] == 0)
			{
				iShowImage(328, 121, 241, 73, save5[0]);
			}
			if (selsave[3] == 0)
			{
				iShowImage(334, 189, 232, 79, save4[0]);
			}
			if (selsave[2] == 0)
			{
				iShowImage(333, 262, 232, 71, save3[0]);
			}
			if (selsave[1] == 0)
			{
				iShowImage(324, 320, 254, 96, save2[0]);
			}
			if (selsave[0] == 0)
			{
				iShowImage(335, 143 + 251, 230, 85, save1[0]);
			}
			if (selsave[4] == 1)
			{
				iShowImage(350 - 26 + 8, 115, 213 + 24, 89, save5[1]);
			}
			if (selsave[3] == 1)
			{
				iShowImage(334, 191, 227, 80, save4[1]);
			}
			if (selsave[2] == 1)
			{
				iShowImage(331, 258, 238, 80, save3[1]);
			}
			if (selsave[1] == 1)
			{
				iShowImage(328, 334, 238, 70, save2[1]);
			}
			if (selsave[0] == 1)
			{
				iShowImage(326, 399, 247, 76, save1[1]);
			}
		}
	}
	if (curtime == 150)
	{
		curtime = 0;
		gamestate = 7;
		tpoint += cpoint;
		checkscore();
		cpoint = 0;
		size = 1;
		b1 = 80;
		b2 = 60;
		movex = 0;
		movey = 0;
		shows = 0;
		timetick = 0;
		for (int k = 0; k < 10; k++)
		{

			showw[k] = 0;
			movexw[k] = 0;
			swx[k] = 0;
			cswx[k] = 0;
			swy[k] = 0;
			mtw[k] = 0;
			dis[k] = 0;
			dir[k] = 0;
			showp[k] = 0;
			movexp[k] = 0;
			spx[k] = 0;
			cspx[k] = 0;
			spy[k] = 0;
			mtp[k] = 0;
			disp[k] = 0;
			dirp[k] = 0;
			showb[k] = 0;
			movexb[k] = 0;
			sbx[k] = 0;
			csbx[k] = 0;
			sby[k] = 0;
			mtb[k] = 0;
			disb[k] = 0;
			dirb[k] = 0;
			cw[k] = 0;
			cp[k] = 0;
			cb[k] = 0;
		}
		//congrats image
	}
}






/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{
	
}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{
	if (gamestate == 1)
	{
		if (mx >= 653 && mx <= 803 && my >= 60 && my <= 117)
		{
			namenext = 1;
		}
		else
		{
			namenext = 0;
		}
	}
	if (gamestate == 2 || gamestate == 1)
	{
		if ((mx <= 842 && mx >= 758) && (my >= 57 && my <= 83))
		{
			highprev = 1;
		}
		else
		{
			highprev = 0;
		}
		if (mx >= 350 - 3 && mx <= 550 + 3 && my >= 130 - 3 && my <= 190 + 3)
		{
			selsave[4] = 1;
		}
		else
		{
			selsave[4] = 0;
		}
		if (mx >= 350 - 3 && mx <= 550 + 3 && my >= 130 + 70 - 3 && my <= 190 + 70 + 3)
		{
			selsave[3] = 1;
		}
		else
		{
			selsave[3] = 0;
		}
		if (mx >= 350 - 3 && mx <= 550 + 3 && my >= 130 + 140 - 3 && my <= 190 + 140 + 3)
		{
			selsave[2] = 1;
		}
		else
		{
			selsave[2] = 0;
		}
		if (mx >= 350 - 3 && mx <= 550 + 3 && my >= 130 + 210 - 3 && my <= 190 + 210 + 3)
		{
			selsave[1] = 1;
		}
		else
		{
			selsave[1] = 0;
		}
		if (mx >= 350 - 3 && mx <= 335 + 230 + 3 && my >= 130 + 280 - 3 && my <= 190 + 280 + 3)
		{
			selsave[0] = 1;
		}
		else
		{
			selsave[0] = 0;
		}
	}
	if (gamestate == 4)
	{
		if (mx >= 398 && mx <= 502 && my >= 248 && my <= 292)
		{
			gpshower = 1;
		}
		else
		{
			gpshower = 0;
		}
		if (mx >= 398 && mx <= 502 && my >= 308 && my <= 352)
		{
			gushower = 1;
		}
		else
		{
			gushower = 0;
		}
		if ((mx <= 842 && mx >= 758) && (my >= 57 && my <= 83))
		{
			highprev = 1;
		}
		else
		{
			highprev = 0;
		}
	}
	if (gamestate == -1)
	{
		if (mx >= 653 && mx <= 803 && my >= 60 && my <= 117)
		{
			namenext = 1;
		}
		else
		{
			namenext = 0;
		}
	}
	if (gamestate == 6 || gamestate == 7)
	{
		if (mx >= 653 && mx <= 803 && my >= 60 && my <= 117)
		{
			namenext = 1;
		}
		else
		{
			namenext = 0;
		}
	}
	if (gamestate == 3)
	{
		
		if ((mx <= 842 && mx >= 758) && (my >= 57 && my <= 83))
		{
			highprev = 1;
		}
		else
		{
			highprev = 0;
		}
	}
	if (gamestate == 8)
	{
		if ((mx <= 842 && mx >= 758) && (my >= 57 && my <= 83))
		{
			highprev = 1;
		}
		else
		{
			highprev = 0;
		}
	}
	if (gamestate == 9)
	{
		if ((mx <= 842 && mx >= 758) && (my >= 57 && my <= 83))
		{
			highprev = 1;
		}
		else
		{
			highprev = 0;
		}
	}
	else if (gamestate == 0)
	{
		if (mx >= 361 && mx <= 539 && my >= 153 && my <= 207)
		{
			sel[4] = 1;
		}
		else
		{
			sel[4] = 0;
		}
		if (mx >= 361 && mx <= 539 && my >= 153 + 60 && my <= 207 + 60)
		{
			sel[3] = 1;
		}
		else
		{
			sel[3] = 0;
		}
		if (mx >= 361 && mx <= 539 && my >= 153 + 120 && my <= 207 + 120)
		{
			sel[2] = 1;
		}
		else
		{
			sel[2] = 0;
		}
		if (mx >= 361 && mx <= 539 && my >= 153 + 180 && my <= 207 + 180)
		{
			sel[1] = 1;
		}
		else
		{
			sel[1] = 0;
		}
		if (mx >= 361 && mx <= 539 && my >= 153 + 240 && my <= 207 + 240)
		{
			sel[0] = 1;
		}
		else
		{
			sel[0] = 0;
		}
	}
}



void iMouse(int button, int state, int mx, int my)
{
	if (gamestate == 1 && paused != 1 && savestate != 1 && savestate != 2 && loaded != 30 && loadstate != 1 && loadstate != 2 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		move = 1;
		s1 = 1;
		s2 = 1;
		nextx = mx;
		nexty = my;
		tx = nextx - (nx + (b1 / 2));
		ty = nexty - (ny + (b2 / 2));
		if ((nx + b1 / 2) < nextx)
		{
			sr[0] = iLoadImage("Player_shark.png");
			fs = 1;
		}
		else
		{
			sr[0] = iLoadImage("Player_shark_2.png");
			fs = 0;
		}
		if ((ny + b2 / 2) < nexty)
		{
			fsy = 1;
		}
		else
		{
			fsy = 0;
		}

		tm = sqrt(1.0*(tx)*(tx)+(ty)*(ty));
	}
	if (gamestate == -1 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		
		if ((mx <= 795 && mx >= 660) && (my >= 65 && my <= 125))
		{
			gamestate = 0;
		}
	}
	if (gamestate == 2 && notsaved==1 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if ((mx <= 842 && mx >= 758) && (my >= 57 && my <= 83))
		{
			notsaved=0;
		}
	}
	else if (gamestate == 2 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if ((mx <= 842 && mx >= 758) && (my >= 57 && my <= 83))
		{
			gamestate = 0;
		}
		if (mx >= 350- 3 && mx <= 550 + 3 && my >= 130 - 3 && my <= 190 + 3)
		{
			//selsave[4] = 1;
			selected = 4;
			if (alsa[selected] != 1)
			{
				notsaved = 1;
			}
			else
			{
				gameloader();
				loaded = 30;
				shows = 1;
				gamestate = 1;
			}
		}
		if (mx >= 350 - 3 && mx <= 550 + 3 && my >= 130 + 70 - 3 && my <= 190 + 70 + 3)
		{
			//selsave[3] = 1;
			selected = 3;
			if (alsa[selected] != 1)
			{
				notsaved = 1;
			}
			else
			{
				gameloader();
				loaded = 30;
				shows = 1;
				gamestate = 1;
			}
		}
		if (mx >= 350 - 3 && mx <= 550 + 3 && my >= 130 + 140 - 3 && my <= 190 + 140 + 3)
		{
			//selsave[2] = 1;
			selected = 2;
			if (alsa[selected] != 1)
			{
				notsaved = 1;
			}
			else
			{
				gameloader();
				loaded = 30;
				shows = 1;
				gamestate = 1;
			}
		}
		if (mx >= 350 - 3 && mx <= 550 + 3 && my >= 130 + 210 - 3 && my <= 190 + 210 + 3)
		{
			//selsave[1] = 1;
			selected = 1;
			if (alsa[selected] != 1)
			{
				notsaved = 1;
			}
			else
			{
				gameloader();
				loaded = 30;
				shows = 1;
				gamestate = 1;
			}
		}
		if (mx >= 350 - 3 && mx <= 335 + 230 + 3 && my >= 130 + 280 - 3 && my <= 190 + 280 + 3)
		{
			//selsave[0] = 1;
			selected = 0;
			if (alsa[selected] != 1)
			{
				notsaved = 1;
			}
			else
			{
				gameloader();
				loaded = 30;
				shows = 1;
				gamestate = 1;
			}
		}
	}
	if (gamestate == 1 && loadstate == 2 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if ((mx <= 842 && mx >= 758) && (my >= 57 && my <= 83))
		{
			loadstate = 1;
			boxh = 0;
		}
	}
	else if (gamestate == 1 && loadstate == 1 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if ((mx <= 842 && mx >= 758) && (my >= 57 && my <= 83))
		{
			//gamestate = 1;
			selected = -1;
			paused = 0;
			loadstate = 0;
			iResumeTimer(indmb);
			iResumeTimer(indmp);
			iResumeTimer(indmw);
			iResumeTimer(indsp);
			iResumeTimer(indsw);
			iResumeTimer(indsb);
			iResumeTimer(indms);
			iResumeTimer(indt);
		}
		if (mx >= 350 - 3 && mx <= 550 + 3 && my >= 130 - 3 && my <= 190 + 3)
		{
			//selsave[4] = 1;
			selected = 4;
			if (alsa[selected] != 1)
			{
				loadstate = 2;
			}
			else
			{
				gameloader();
				loaded = 30;
				shows = 1;
				gamestate = 1;
				//paused = 0;
				loadstate = 0;
				iResumeTimer(indmb);
				iResumeTimer(indmp);
				iResumeTimer(indmw);
				iResumeTimer(indsp);
				iResumeTimer(indsw);
				iResumeTimer(indsb);
				iResumeTimer(indms);
				iResumeTimer(indt);
			}
		}
		if (mx >= 350 - 3 && mx <= 550 + 3 && my >= 130 + 70 - 3 && my <= 190 + 70 + 3)
		{
			//selsave[3] = 1;
			selected = 3;
			if (alsa[selected] != 1)
			{
				loadstate = 2;
			}
			else
			{
				gameloader();
				loaded = 30;
				shows = 1;
				gamestate = 1;
				//paused = 0;
				loadstate = 0;
				iResumeTimer(indmb);
				iResumeTimer(indmp);
				iResumeTimer(indmw);
				iResumeTimer(indsp);
				iResumeTimer(indsw);
				iResumeTimer(indsb);
				iResumeTimer(indms);
				iResumeTimer(indt);
			}
		}
		if (mx >= 350 - 3 && mx <= 550 + 3 && my >= 130 + 140 - 3 && my <= 190 + 140 + 3)
		{
			//selsave[2] = 1;
			selected = 2;
			if (alsa[selected] != 1)
			{
				loadstate = 2;
			}
			else
			{
				gameloader();
				loaded = 30;
				shows = 1;
				gamestate = 1;
				//paused = 0;
				loadstate = 0;
				iResumeTimer(indmb);
				iResumeTimer(indmp);
				iResumeTimer(indmw);
				iResumeTimer(indsp);
				iResumeTimer(indsw);
				iResumeTimer(indsb);
				iResumeTimer(indms);
				iResumeTimer(indt);
			}
		}
		if (mx >= 350 - 3 && mx <= 550 + 3 && my >= 130 + 210 - 3 && my <= 190 + 210 + 3)
		{
			//selsave[1] = 1;
			selected = 1;
			if (alsa[selected] != 1)
			{
				loadstate = 2;
			}
			else
			{
				gameloader();
				loaded = 30;
				shows = 1;
				gamestate = 1;
				//paused = 0;
				loadstate = 0;
				iResumeTimer(indmb);
				iResumeTimer(indmp);
				iResumeTimer(indmw);
				iResumeTimer(indsp);
				iResumeTimer(indsw);
				iResumeTimer(indsb);
				iResumeTimer(indms);
				iResumeTimer(indt);
			}
		}
		if (mx >= 350 - 3 && mx <= 335 + 230 + 3 && my >= 130 + 280 - 3 && my <= 190 + 280 + 3)
		{
			//selsave[0] = 1;
			selected = 0;
			if (alsa[selected] != 1)
			{
				loadstate = 2;
			}
			else
			{
				gameloader();
				loaded = 30;
				shows = 1;
				gamestate = 1;
				//paused = 0;
				loadstate = 0;
				iResumeTimer(indmb);
				iResumeTimer(indmp);
				iResumeTimer(indmw);
				iResumeTimer(indsp);
				iResumeTimer(indsw);
				iResumeTimer(indsb);
				iResumeTimer(indms);
				iResumeTimer(indt);
			}
		}
	}
	if (gamestate == 3 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if ((mx <= 842 && mx >= 758) && (my >= 57 && my <= 83))
		{
			gamestate = 0;
		}
	}
	if (gamestate == 4 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		
		if (mx >= 398 && mx <= 502 && my >= 248 && my <= 292)
		{
			gamestate = 8;
		}
		else if (mx >= 398 && mx <= 502 && my >= 248 + 60 && my <= 292 + 60)
		{
			gamestate = 9;
		}
		if ((mx <= 842 && mx >= 758) && (my >= 57 && my <= 83))
		{
			gamestate = 0;
		}
	}
	else if (gamestate == 8 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if ((mx <= 842 && mx >= 758) && (my >= 57 && my <= 83))
		{
			gamestate = 0;
		}
	}
	else if (gamestate == 9 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if ((mx <= 842 && mx >= 758) && (my >= 57 && my <= 83))
		{
			gamestate = 0;
		}
	}
	if ((gamestate == 6 || gamestate == 7) && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (mx >= 653 && mx <= 803 && my >= 60 && my <= 117)
		{
			gamestate = 0;
			congoshower = 0;
		}
	}
	if (gamestate == 1 && savestate == 2 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (mx >= 653 && mx <= 803 && my >= 60 && my <= 117)
		{
			sbpressed = 1;
			savebuffer = 10;
		}
	}
	if (gamestate == 1 && savestate==1 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if ((mx <= 842 && mx >= 758) && (my >= 57 && my <= 83))
		{
			savestate = 0;
			selected = -1;
			iResumeTimer(indmb);
			iResumeTimer(indmp);
			iResumeTimer(indmw);
			iResumeTimer(indsp);
			iResumeTimer(indsw);
			iResumeTimer(indsb);
			iResumeTimer(indms);
			iResumeTimer(indt); 
			
		}
		if (mx >= 350 - 3 && mx <= 550 + 3 && my >= 130 - 3 && my <= 190 + 3)
		{
			//selsave[4] = 1;
			selected = 4;
			alsa[selected] = 1;
			gamesaver();
			savestate = 2;
		}
		if (mx >= 350 - 3 && mx <= 550 + 3 && my >= 130 + 70 - 3 && my <= 190 + 70 + 3)
		{
			//selsave[3] = 1;
			selected = 3;
			alsa[selected] = 1;
			gamesaver();
			savestate = 2;
		}
		if (mx >= 350 - 3 && mx <= 550 + 3 && my >= 130 + 140 - 3 && my <= 190 + 140 + 3)
		{
			//selsave[2] = 1;
			selected = 2;
			alsa[selected] = 1;
			gamesaver();
			savestate = 2;
		}
		if (mx >= 350 - 3 && mx <= 550 + 3 && my >= 130 + 210 - 3 && my <= 190 + 210 + 3)
		{
			//selsave[1] = 1;
			selected = 1;
			alsa[selected] = 1;
			gamesaver();
			savestate = 2;
		}
		if (mx >= 350 - 3 && mx <= 335 + 230 + 3 && my >= 130 + 280 - 3 && my <= 190 + 280 + 3)
		{
			//selsave[0] = 1;
			selected = 0;
			alsa[selected] = 1;
			gamesaver();
			savestate = 2;
		}
	}
	
	
	if (gamestate == 0 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (mx >= 361 && mx <= 539 && my >= 153 && my <= 207)
		{
			exit(0);
		}
		if (mx >= 361 && mx <= 539 && my >= 153 + 60 && my <= 207 + 60)
		{
			gamestate = 4;
		}
		if (mx >= 361 && mx <= 539 && my >= 153 + 120 && my <= 207 + 120)
		{
			gamestate = 3;
		}
		if (mx >= 361 && mx <= 539 && my >= 153 + 180 && my <= 207 + 180)
		{
			gamestate = 2;
		}
		if (mx >= 361 && mx <= 539 && my >= 153 + 240 && my <= 207 + 240)
		{
			gamestate = 1;
			shows = 1;
		}
	}
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	if (key == 27 && gamestate == 1 && shows == 1)
	{
		curtime = 0;
		gamestate = 0;
		tpoint += cpoint;
		checkscore();
		cpoint = 0;
		size = 1;
		b1 = 80;
		b2 = 60;
		movex = 0;
		movey = 0;
		shows = 0;
		timetick = 0;
		for (int k = 0; k < 10; k++)
		{

			showw[k] = 0;
			movexw[k] = 0;
			swx[k] = 0;
			cswx[k] = 0;
			swy[k] = 0;
			mtw[k] = 0;
			dis[k] = 0;
			dir[k] = 0;
			showp[k] = 0;
			movexp[k] = 0;
			spx[k] = 0;
			cspx[k] = 0;
			spy[k] = 0;
			mtp[k] = 0;
			disp[k] = 0;
			dirp[k] = 0;
			showb[k] = 0;
			movexb[k] = 0;
			sbx[k] = 0;
			csbx[k] = 0;
			sby[k] = 0;
			mtb[k] = 0;
			disb[k] = 0;
			dirb[k] = 0;
			cw[k] = 0;
			cp[k] = 0;
			cb[k] = 0;
		}
	}
	if (key == 'l' && gamestate == 1 && shows == 1)
	{
		boxh = 0;
		loadstate = 1;
		iPauseTimer(indmb);
		iPauseTimer(indmp);
		iPauseTimer(indmw);
		iPauseTimer(indsp);
		iPauseTimer(indsw);
		iPauseTimer(indsb);
		iPauseTimer(indms);
		iPauseTimer(indt);

	}
	if (key == 'r' && gamestate == 1 && shows == 1)
	{
		paused = 0;
		iResumeTimer(indmb);
		iResumeTimer(indmp);
		iResumeTimer(indmw);
		iResumeTimer(indsp);
		iResumeTimer(indsw);
		iResumeTimer(indsb);
		iResumeTimer(indms);
		iResumeTimer(indt);
		
	}
	else if (key == 'p' && gamestate == 1 && shows == 1)
	{
		paused = 1;
		iPauseTimer(indmb);
		iPauseTimer(indmp);
		iPauseTimer(indmw);
		iPauseTimer(indsp);
		iPauseTimer(indsw);
		iPauseTimer(indsb);
		iPauseTimer(indms);
		iPauseTimer(indt);
	}
	else if (key == 's' && gamestate == 1 && shows == 1)
	{
		boxh = 0;
		savestate = 1;
		iPauseTimer(indmb);
		iPauseTimer(indmp);
		iPauseTimer(indmw);
		iPauseTimer(indsp);
		iPauseTimer(indsw);
		iPauseTimer(indsb);
		iPauseTimer(indms);
		iPauseTimer(indt);
	}
	/*else if (key == 'r' && option == 0 && gamestate == 0)
	{
		gamestate = 1;
		shows = 1;
	}
	else if (key == 'r' && option == 2 && gamestate == 0)
	{
		gamestate = 3;
	}
	else if (key == 'r' && gamestate == 7)
	{
		gamestate = 0;
	}*/
	else if (gamestate == -1)
	{
		char a = key;
		
		if (fletpre >= 1 && key == '\r')
		{
			gamestate = 0;
			
			//++;
		}
		else if (fletpre >= 1 && fletpre <= 30 && key=='\b')
		{
			pname[fletpre - 1] = '\0';
			fletpre--;
		}
		else if (fletpre >= 1 && fletpre<=30 &&((key >= 'a' && key <= 'z') || (key >= 'A' && key <= 'Z') || key == ' '))
		{
			strncat(pname, &a, 1);
			fletpre++; 
		}
		else if (fletpre == 0 && key == '\r')
		{
			gamestate = 0;
		}
		else if (fletpre == 0 && key == 'a')
		{
			strcpy(pname, "a");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'b')
		{
			strcpy(pname, "b");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'c')
		{
			strcpy(pname, "c");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'd')
		{
			strcpy(pname, "d");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'e')
		{
			strcpy(pname, "e");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'f')
		{
			strcpy(pname, "f");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'g')
		{
			strcpy(pname, "g");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'h')
		{
			strcpy(pname, "h");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'i')
		{
			strcpy(pname, "i");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'j')
		{
			strcpy(pname, "j");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'k')
		{
			strcpy(pname, "k");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'l')
		{
			strcpy(pname, "l");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'm')
		{
			strcpy(pname, "m");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'n')
		{
			strcpy(pname, "n");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'o')
		{
			strcpy(pname, "o");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'p')
		{
			strcpy(pname, "p");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'q')
		{
			strcpy(pname, "q");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'r')
		{
			strcpy(pname, "r");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 's')
		{
			strcpy(pname, "s");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 't')
		{
			strcpy(pname, "t");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'u')
		{
			strcpy(pname, "u");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'v')
		{
			strcpy(pname, "v");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'w')
		{
			strcpy(pname, "w");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'x')
		{
			strcpy(pname, "x");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'y')
		{
			strcpy(pname, "y");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'z')
		{
			strcpy(pname, "z");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'A')
		{
			strcpy(pname, "A");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'B')
		{
			strcpy(pname, "B");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'C')
		{
			strcpy(pname, "C");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'D')
		{
			strcpy(pname, "D");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'E')
		{
			strcpy(pname, "E");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'F')
		{
			strcpy(pname, "F");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'G')
		{
			strcpy(pname, "G");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'H')
		{
			strcpy(pname, "H");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'I')
		{
			strcpy(pname, "I");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'J')
		{
			strcpy(pname, "J");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'K')
		{
			strcpy(pname, "K");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'L')
		{
			strcpy(pname, "L");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'M')
		{
			strcpy(pname, "M");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'N')
		{
			strcpy(pname, "N");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'O')
		{
			strcpy(pname, "O");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'P')
		{
			strcpy(pname, "P");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'Q')
		{
			strcpy(pname, "Q");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'R')
		{
			strcpy(pname, "R");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'S')
		{
			strcpy(pname, "S");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'T')
		{
			strcpy(pname, "T");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'U')
		{
			strcpy(pname, "U");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'V')
		{
			strcpy(pname, "V");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'W')
		{
			strcpy(pname, "W");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'X')
		{
			strcpy(pname, "X");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'Y')
		{
			strcpy(pname, "Y");
			fletpre = 1;
		}
		else if (fletpre == 0 && key == 'Z')
		{
			strcpy(pname, "Z");
			fletpre = 1;
		}
	}
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
	/*"/r"
	if (key == GLUT_KEY_DOWN)
	{
		if (gamestate == 0)
		{
			option++;
			if (option == 5)
			{
				option = 0;
			}
		}
		if (gamestate == 1)
		{
			movey -= 5;
			ny = ny + movey;
		}
	}
	if (key == GLUT_KEY_UP)
	{
		if (gamestate == 0)
		{
			option--;
			if (option == -1)
			{
				option = 4;
			}
		}
		if (gamestate == 1)
		{
			movey += 5;
			ny = ny + movey;
		}
	}
	
	if (key == GLUT_KEY_LEFT)
	{
		/*if (gamestate == 1)
		{
			sr[0] = iLoadImage("Player_shark_2.png");
			fs = 0;
			movex -= 5;
			nx = nx + movex;
		}
	}
	if (key == GLUT_KEY_RIGHT)
	{
		/*if (gamestate == 1)
		{
			sr[0] = iLoadImage("Player_shark.png");
			fs = 1;
			movex += 5;
			nx = nx + movex;
		}
	}*/
	//if (key == GLUT_KEY_RIGHT && gamestate)
}


int main()
{
	///srand((unsigned)time(NULL));
	iInitialize(900, 600, "Hunter Shark");
	///updated see the documentations
	congoimage = iLoadImage("congrats1.png");
	background[0] = iLoadImage("1.png");
	background[1] = iLoadImage("2.png");
	background[2] = iLoadImage("3.png");
	background[3] = iLoadImage("4.png");
	background[4] = iLoadImage("5.png");
	previous[0] = iLoadImage("Previous.png");
	next[0] = iLoadImage("Next.png");
	previous[1] = iLoadImage("Previous Highlight.png");
	next[1] = iLoadImage("Next Highlight.png");
	BACKGROUND = iLoadImage("bg2.jpg");
	opbackground = iLoadImage("opbackground.jpg");
	bg[0] = iLoadImage("background2.jpg");
	goimage = iLoadImage("gameover.jpg");
	sr[0] = iLoadImage("Player_shark.png");
	ng[0] = iLoadImage("Front 01.png");	//
	lg[0] = iLoadImage("Front 02.png");
	lb[0] = iLoadImage("Front 03.png");
	inst[0] = iLoadImage("Front 04.png");
	ex[0] = iLoadImage("Front 05.png");
	ng[1] = iLoadImage("Front 06.png");	//Front 01
	lg[1] = iLoadImage("Front 07.png");
	lb[1] = iLoadImage("Front 08.png");
	inst[1] = iLoadImage("Front 09.png");
	ex[1] = iLoadImage("Front 10.png");
	chrunch = iLoadImage("crunch.png");
	gp = iLoadImage("Gameplay.png");
	gph = iLoadImage("Gameplay Highlight.png");
	gu = iLoadImage("Guide.png");
	guh = iLoadImage("Guide Highlight.png");
	gps = iLoadImage("Gameplayscrn.png");
	gus = iLoadImage("Guidescrn.png");
	optionpic = iLoadImage("Background.jpg");
	leaderboard = iLoadImage("leaderboard.png");
	save1[0] = iLoadImage("Save 01.png");
	save2[0] = iLoadImage("Save 02.png");
	save3[0] = iLoadImage("Save 03.png");
	save4[0] = iLoadImage("Save 04.png");
	save5[0] = iLoadImage("Save 05.png");
	save1[1] = iLoadImage("Save highlight 01.png");
	save2[1] = iLoadImage("Save highlight 02.png");
	save3[1] = iLoadImage("Save highlight 03.png");
	save4[1] = iLoadImage("Save highlight 04.png");
	save5[1] = iLoadImage("Save highlight 05.png");
	pausedbg = iLoadImage("bg1.jpg");
	pausepic = iLoadImage("paused.png");
	notsavedimage = iLoadImage("nosavedgame.jpg");
	//sl[0] = iLoadImage("Player_shark_2.png");pausepic
	indt = iSetTimer(1000, timei);
	indms = iSetTimer(5, sharkmove);
	indsp = iSetTimer(1500, spawnp);
	indmp = iSetTimer(5, movep);
	indsb = iSetTimer(5000, spawnb);
	indmb = iSetTimer(5, moveb);
	indsw = iSetTimer(7000, spawnw);
	indmw = iSetTimer(5, movew);
	/*if (mainmenumusic == 1)
	{
		PlaySound("mainmenumusic.wav", NULL, SND_LOOP | SND_ASYNC);
	}*/
	iStart();
	//if (gamestate != 5)
	return 0;
		
}
