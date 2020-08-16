#include<stdio.h>
int main(void)
{
	unsigned int gradeA, gradeB, gradeC;
	while (!feof (stdin))
	{
		scanf("%d %d %d", &gradeA, &gradeB, &gradeC);
		if (gradeA == gradeB && gradeB == gradeC)
		{
			printf("A:%d\n", gradeA);
		}
		else if (gradeA > gradeB && gradeA > gradeC)
		{
			if (gradeB >= gradeC)
				printf("B:%d\n", gradeB);
			else
				printf("C:%d\n", gradeC);
		}
		else if (gradeB > gradeA && gradeB > gradeC)
		{
			if (gradeA >= gradeC)
				printf("A:%d\n", gradeA);
			else
				printf("C:%d\n", gradeC);
		}
		else if (gradeC > gradeA && gradeC > gradeB)
		{
			if (gradeA >= gradeB)
				printf("A:%d\n", gradeA);
			else
				printf("B:%d\n", gradeB);
		}
		else if (gradeA == gradeB && gradeA > gradeC)
		{
			printf("A:%d\n", gradeA);
		}
		else if (gradeA == gradeC && gradeA > gradeB)
		{
			printf("A:%d\n", gradeA);
		}
		else if (gradeB == gradeC && gradeB > gradeA)
		{
			printf("B:%d\n", gradeB);
		}
	}
	return 0;
}