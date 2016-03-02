/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/


int isOlder(char *dob1, char *dob2) {
	int i, len1 = 0, len2 = 0;
	for (len1; dob1[len1]; len1++);
	for (len2; dob2[len2]; len2++);
	if (len1 == len2)
	{
		for (i = 0; i<len1 || i<len2; i++)
		{
			if ((dob1[i] <'0' || dob1[i] >'9') || (dob2[i] <'0' || dob2[i] >'9'))
				if ((dob1[i] != '-') || (dob2[i] != '-'))
					return -1;
		}
		int d1 = 0, d2 = 0, m1 = 0, m2 = 0, y1 = 0, y2 = 0;
		for (i = 0; dob1[i] && dob2[i]; i++)
		{
			if (i < 2)
			{
				if (dob1[i] != '-')
					d1 += dob1[i] - '0';
				if (dob2[i] != '-')
					d2 += dob2[i] - '0';
				if (dob1[i + 1] != '-')
					d1 *= 10;
				if (dob2[i + 1] != '-')
					d2 *= 10;
			}
			else if (i>2 && i < 5)
			{
				if (dob1[i] != '-')
					m1 += dob1[i] - '0';
				if (dob2[i] != '-')
					m2 += dob2[i] - '0';
				if (dob1[i + 1] != '-')
					m1 *= 10;
				if (dob2[i + 1] != '-')
					m2 *= 10;
			}
			else if (i > 5 && i < 10)
			{
				if (dob1[i] != '-')
					y1 += dob1[i] - '0';
				if (dob2[i] != '-')
					y2 += dob2[i] - '0';
				if (dob1[i + 1] != '-'&&dob1[i + 1] != '\0')
					y1 *= 10;
				if (dob2[i + 1] != '-'&&dob2[i + 1] != '\0')
					y2 *= 10;
			}
		}
		if (y1 == y2)
		{
			if (m1 == m2&&m1<13 && m2<13)
			{
				if ((d1 == d2) && d1>0 && d1 < 32 && d2>0 && d2 < 32 && m1 != 2)
					return 0;
				else if ((d1 < d2) && d1>0 && d1 < 32 && d2>0 && d2 < 32 && m1 != 2)
					return 1;
				else if ((d1 > d2) && d1 > 0 && d1 < 32 && d2>0 && d2 < 32 && m1 != 2)
					return 2;
				else if (m1 == 2 && m2 == 2)
				{
					if ((y1 % 4 == 0 && y1 % 100 != 0 || y1 % 400 == 0) || (y2 % 4 == 0 && y2 % 100 != 0 || y2 % 400 == 0) && d1>0 && d2 > 0 && d1 < 30 && d2 < 30)
					{
						if (d1 == d2)
							return 0;
						else if (d1 < d2)
							return 1;
						else if (d1 > d2)
							return 2;
						else
							return -1;
					}
					else if (d1 < 29 && d2 < 29)
					{
						if (d1 == d2)
							return 0;
						else if (d1 < d2)
							return 1;
						else if (d1 > d2)
							return 2;
						else
							return -1;
					}

				}
				else
					return -1;
			}
			else if ((m1 < m2) && m1 > 0 && m2 > 0 && m1 < 13 && m2 < 13)
			{
				return 1;
			}
			else if ((m1 > m2) && m1 > 0 && m2 > 0 && m1 < 13 && m2 < 13)
			{
				return 2;
			}
		}
		else if (y1 < y2){
			if (m1 == 2)
			{
				if (y1 % 4 == 0 && y1 % 100 != 0 || y1 % 400 == 0)
				{
					if (d1 >30)
						return -1;
				}
				else if (d1 >29)
				{
					return -1;
				}
			}
			else if (m2 == 2)
			{
				if (y2 % 4 == 0 && y2 % 100 != 0 || y2 % 400 == 0){
					if (d2 > 30)
						return -1;
				}
				else if (d2 > 29)
					return -1;
			}
			return 1;
		}
		else if (y1 > y2){
			if (m1 == 2)
			{
				if (y1 % 4 == 0 && y1 % 100 != 0 || y1 % 400 == 0)
				{
					if (d1 >30)
						return -1;
				}
				else if (d1 >28)
				{
					return -1;
				}
			}
			else if (m2 == 2)
			{
				if (y2 % 4 == 0 && y2 % 100 != 0 || y2 % 400 == 0){
					if (d2 > 30)
						return -1;
				}
				else if (d2 > 28)
					return -1;
			}
			return 2;
		}
	}
	return -1;

}



