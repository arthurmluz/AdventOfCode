#include <stdio.h>
#define SIZE 2000

int main()
{
  char First, Second, Line[100], Area[SIZE][SIZE];
  int Steady, RangeMin, RangeMax, XMin, XMax, YMin, YMax, Count, InnerCount;
  int SideCount, LeftBound, RightBound, TotalArea;
  bool Changed, LeftBounded, RightBounded;
  for (Count=0;Count<SIZE;Count++)
    for (InnerCount=0;InnerCount<SIZE;InnerCount++)
      Area[Count][InnerCount] = '.';
  XMin=XMax=464;
  YMin=YMax=310;
  while (fgets(Line, 90, stdin))
    {
      sscanf(Line, "%c=%d, %c=%d..%d\n", &First, &Steady, &Second, &RangeMin, &RangeMax);
      if (Second=='x')
	{
	  for (Count=RangeMin;Count<=RangeMax;Count++)
	    Area[Steady][Count] = '#';
	  if (RangeMin<XMin)
	    XMin=RangeMin;
	  if (RangeMin>XMax)
	    XMax=RangeMin;
	  if (RangeMax<XMin)
	    XMin=RangeMin;
	  if (RangeMax>XMax)
	    XMax=RangeMin;
	  if (Steady<YMin)
	    YMin=Steady;
	  if (Steady>YMax)
	    YMax=Steady;
	}
      else
	{
	  for (Count=RangeMin;Count<=RangeMax;Count++)
	    Area[Count][Steady] = '#';
	  if (RangeMin<YMin)
	    YMin=RangeMin;
	  if (RangeMin>YMax)
	    YMax=RangeMin;
	  if (RangeMax<YMin)
	    YMin=RangeMin;
	  if (RangeMax>YMax)
	    YMax=RangeMin;
	  if (Steady<XMin)
	    XMin=Steady;
	  if (Steady>XMax)
	    XMax=Steady;
	}
    }
  printf("X: %d %d Y: %d %d\n", XMin, XMax, YMin, YMax);
  Changed = true;
  Area[0][500] = '|';
  printf("%c\n", Area[0][500]);
  for (Count=0;Count<=YMax;Count++)
    {
      for (InnerCount=(XMin-2);InnerCount<=(XMax+2);InnerCount++)
	printf("%c", Area[Count][InnerCount]);
      printf("\n");
    }
  while (Changed)
    {
      Changed = false;
      for (Count=0;Count<=YMax;Count++)
	for (InnerCount=(XMin-2);InnerCount<=(XMax+2);InnerCount++)
	  {
	    if (Area[Count][InnerCount]=='|')
	      {
		if (Area[Count+1][InnerCount] == '.')
		  {
		    Area[Count+1][InnerCount] = '|';
		    Changed=true;
		  }
		else if ((Area[Count+1][InnerCount] == '#') || (Area[Count+1][InnerCount] == '~'))
		  {
		    LeftBounded = RightBounded = false;
		    SideCount=1;
		    while ((Area[Count][InnerCount-SideCount] != '#') && ((Area[Count+1][InnerCount-SideCount] == '#') || (Area[Count+1][InnerCount-SideCount] == '~')))
		      {
			if (Area[Count][InnerCount-SideCount]=='.')
			  {
			    Area[Count][InnerCount-SideCount]='|';
			    Changed=true;
			  }
			SideCount++;
		      }
		    if (Area[Count][InnerCount-SideCount] == '#')
		      {
			LeftBounded = true;
			LeftBound = -SideCount;
		      }
		    else
		      {
			if (Area[Count][InnerCount-SideCount]=='.')
			  {
			    Area[Count][InnerCount-SideCount]='|';
			    Changed=true;
			  }
		      }
		    SideCount=1;
		    while ((Area[Count][InnerCount+SideCount] != '#') && ((Area[Count+1][InnerCount+SideCount] == '#') || (Area[Count+1][InnerCount+SideCount] == '~')))
		      {
			if (Area[Count][InnerCount+SideCount]=='.')
			  {
			    Area[Count][InnerCount+SideCount]='|';
			    Changed=true;
			  }
			SideCount++;
		      }
		    if (Area[Count][InnerCount+SideCount] == '#')
		      {
			RightBounded = true;
			RightBound = SideCount;
		      }
		    else
		      {
			if (Area[Count][InnerCount+SideCount]=='.')
			  {
			    Area[Count][InnerCount+SideCount]='|';
			    Changed=true;
			  }
		      }
		    if (LeftBounded && RightBounded)
		      {
			for (SideCount = LeftBound+1;SideCount < RightBound; SideCount++)
			  {
			    if (Area[Count][InnerCount+SideCount]!='~')
			      {
				Area[Count][InnerCount+SideCount]='~';
				Changed=true;
			      }
			  }
		      }
		  }
	      }
	  }
    }
  printf("Final:\n");
  for (Count=0;Count<=YMax;Count++)
    {
      for (InnerCount=(XMin-2);InnerCount<=(XMax+2);InnerCount++)
	printf("%c", Area[Count][InnerCount]);
      printf("\n");
    }
  TotalArea=0;
  for (Count=YMin;Count<=YMax;Count++)
    for (InnerCount=(XMin-2);InnerCount<=(XMax+2);InnerCount++)
      if ( (Area[Count][InnerCount] == '~'))
	{
	  TotalArea++;
	}
  printf("Total:, %d", TotalArea);
}
