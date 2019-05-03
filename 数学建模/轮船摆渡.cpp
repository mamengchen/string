#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define PERSON_MAX 150
#define ALL_TIME 600
#define BOAT_TIME 90

struct Boat {
	Boat()
	{
		_person = 0;
		_count = 0;
		_Boatcost = 0;
	}

	void chang_person(int num)
	{
		_person = num;
	}
	void chang_count(int num)
	{
		_count = num;
	}
	void chang_Boatcost(int num)
	{
		_Boatcost = num;
	}

	void add_count()
	{
		_count++;
	}
	int _person;
	int _count;
	int _Boatcost;
};

struct Boat_queue
{
	Boat_queue(int n)
	{
		boat = new Boat[n * 2];
		BTime = ALL_TIME;
		boat_num = n;
	}

	Boat* boat;
	int BTime;
	int boat_num;
};

void meun()
{
	printf("-----------------------------------------------------------------------------------------------------\n");
	printf("|1.如果轮船公司只有1艘游轮，问该轮船如何安排航程？一天总载客量是多少?                               |\n");
	printf("|2.若轮船公司有多艘轮船，问轮船公司最少需使用几艘游轮？分别如何安排航程？每艘船载客量是多少？       |\n");
	printf("|3.假设游客到达港口最多等待10分钟，若10分钟游轮未到，则自动离开。请在该假设下重新考虑问题?          |\n");
	printf("|4.假设游客到达港口最多等待10分钟，若10分钟游轮未到，则自动离开。请在该假设下重新考虑问题?          |\n");
	printf("|                                        0.exit                                                     |\n");
	printf("-----------------------------------------------------------------------------------------------------\n");
}

void one_boat_muchtime()
{
	Boat_queue que(1);
	int boat_monery = 0;
	int person_monery = 0;
	int all_monery;
	bool judge = false;
	int count = 0;
	char buffer[1024] = { 0 };
	system("cls");
	printf("游轮需要维护的钱数：");
	std::cin >> boat_monery;
	printf("每一个人的船票：");
	std::cin >> person_monery;

	FILE* fp = fopen("./oneboat.txt", "w");
	if (fp == NULL)
	{
		printf("文件打开失败!!!\n");
	}
	for (int i = 90; i <= PERSON_MAX; i += 3)
	{
		que.boat->chang_count(0);
		que.boat->chang_person(i);
		que.boat->chang_Boatcost(boat_monery);
		int all_time = que.BTime - (i / 3);
		que.boat->add_count();
		int person_number = 0;
		while ((all_time - BOAT_TIME) > 0)
		{
			all_time = all_time - BOAT_TIME;
			que.boat->add_count();
		}
		if (all_time)
		{
			judge = true;
			all_monery = i * person_monery + PERSON_MAX * person_monery *(que.boat->_count - 1) - boat_monery * que.boat->_count;
			person_number = PERSON_MAX * (que.boat->_count - 1) + i;
			count = que.boat->_count;
		}
		printf("游轮第一次上有[%d]个人，总人数为<%d>，游轮出行次数{%d}---总利润为:%d;\n", i, person_number, count, all_monery);
		sprintf(buffer, "游轮第一次上有[%d]个人，总人数为<%d>，游轮出行次数{%d}---总利润为:%d;\n", i, person_number, count, all_monery);
		fwrite(&buffer, strlen(buffer), 1, fp);
	}

	system("pause");
}

void much_boat_muchtime()
{
	Boat_queue que(2);
	int boat_monery = 0;
	int person_monery = 0;
	int all_monery;
	char buffer[1024] = { 0 };
	system("cls");
	printf("游轮需要维护的钱数：");
	std::cin >> boat_monery;
	printf("每一个人的船票：");
	std::cin >> person_monery;

	FILE* fp = fopen("./muchboat.txt", "w");
	if (fp == NULL)
	{
		printf("文件打开失败!!!\n");
	}
	for (int i = 90; i <= PERSON_MAX; i += 3)
	{
		for (int j = 90; j <= PERSON_MAX; j += 3)
		{
			que.boat->chang_count(0);
			que.boat->chang_person(i);
			que.boat->chang_Boatcost(boat_monery);
			que.boat[1].chang_count(0);
			que.boat[1].chang_person(j);
			que.boat[1].chang_Boatcost(boat_monery);
			int person_number = 0;
			int all_time = que.BTime - (i / 3);
			all_time = all_time - (j / 3);
			if ((90 - i / 3 - j / 3) > 0)
			{
				while ((all_time - BOAT_TIME) > 0)
				{
					all_time = all_time - BOAT_TIME;
					que.boat->add_count();
					que.boat[1].add_count();
				}
				if ((all_time * 3) > 90)
				{
					que.boat->add_count();
					all_monery = (i * (que.boat->_count - 1) + all_time * 3) * person_monery - boat_monery * que.boat->_count +
						(j*(que.boat[1]._count - 1) + all_time * 3) * person_monery - boat_monery * (que.boat[1]._count - 1);
					person_number = i * (que.boat->_count - 1) + all_time * 3 + j * (que.boat[1]._count - 1) + all_time * 3;
				}
				else
				{
					all_monery = (i * que.boat->_count) * person_monery - boat_monery * que.boat->_count
						+ (j*(que.boat[1]._count - 1) + all_time * 3) * person_monery - boat_monery * (que.boat[1]._count - 1);
					person_number = i * que.boat->_count + j * (que.boat[1]._count - 1) + all_time * 3;
				}

				printf("第一艘游轮上有[%d]个人，第二艘游轮上有[%d]个人，第一个游轮出行次数{%d}，第二个游轮出行次数{%d}，总计人数<%d>---总利润为:%d;\n", i, j, que.boat->_count, que.boat[1]._count, person_number, all_monery);
				sprintf(buffer, "第一艘游轮上有[%d]个人，第二艘游轮上有[%d]个人，第一个游轮出行次数{%d}，第二个游轮出行次数{%d}，总计人数<%d>---总利润为:%d;\n", i, j, que.boat->_count, que.boat[1]._count, person_number, all_monery);
				fwrite(&buffer, strlen(buffer), 1, fp);
			}
			else
			{
				que.boat->add_count();
				que.boat[1].add_count();
				int remain_person = 0;
				while ((all_time * 3) > 150)
				{
					if ((all_time - i / 3) > 0)
					{
						que.boat->add_count();
						all_time -= i / 3;
					}

					if ((all_time - j / 3) > 0)
					{
						que.boat[1].add_count();
						all_time -= j / 3;
					}
					if ((all_time * 3) >= 90 && (all_time * 3) <= 150)
					{
						remain_person = all_time * 3;
					}
				}
				all_monery = (i * que.boat->_count + remain_person + j * que.boat[1]._count) * person_monery
					- (que.boat->_count + que.boat[1]._count + !!(remain_person))*boat_monery;
				int first_boat_number;
				int second_boat_number;
				if (que.boat->_count == que.boat[1]._count)
				{
					first_boat_number = (que.boat->_count + !!(remain_person));
					second_boat_number = (que.boat[1]._count);
				}
				else {
					first_boat_number = (que.boat->_count);
					second_boat_number = (que.boat[1]._count + !!(remain_person));
				}
				printf("第一艘游轮上有[%d]个人，第二艘游轮上有[%d]个人，第一个游轮出行次数{%d}，第二个游轮出行次数{%d}，总计人数<%d>---总利润为:%d;\n", i, j, first_boat_number, second_boat_number, i * que.boat->_count + remain_person + j * que.boat[1]._count, all_monery);
				sprintf(buffer, "第一艘游轮上有[%d]个人，第二艘游轮上有[%d]个人，第一个游轮出行次数{%d}，第二个游轮出行次数{%d}，总计人数<%d>---总利润为:%d;\n", i, j,
					first_boat_number, second_boat_number, i * que.boat->_count + remain_person + j * que.boat[1]._count, all_monery);
				fwrite(&buffer, strlen(buffer), 1, fp);
			}
		}
	}
	system("pause");
}

void wait_one_boat_muchtime()
{
	Boat_queue que(1);
	int boat_monery = 0;
	int person_monery = 0;
	int all_monery;
	char buffer[1024] = { 0 };
	system("cls");
	printf("游轮需要维护的钱数：");
	std::cin >> boat_monery;
	printf("每一个人的船票：");
	std::cin >> person_monery;
	FILE* fp = fopen("./waitoneboat.txt", "w");
	if (fp == NULL)
	{
		printf("文件打开失败!!!\n");
	}

	for (int i = 90; i <= PERSON_MAX; i += 3)
	{
		que.boat->chang_count(0);
		que.boat->chang_person(i);
		que.boat->chang_Boatcost(boat_monery);
		int all_time = que.BTime;
		int once_time = i / 3 - 10 + BOAT_TIME;
		int person_number = 0;
		while ((all_time - once_time) > 0)
		{
			all_time -= once_time;
			que.boat->add_count();
		}
		if ((all_time) > (i / 3 - 10))
		{
			int data = (all_time * 3) < 150 ? all_time * 3 : 150;
			que.boat->add_count();
			person_number = (data + (que.boat->_count - 1)*i);
			all_monery = person_number * person_monery - que.boat->_count * boat_monery;
			printf("每次游轮上有[%d]个人，最后一次尽可能多带一些则游轮上有[%d]个人，游船出行次数{%d}，总计人数<%d>---总利润为:%d;\n", i, data, que.boat->_count, person_number, all_monery);
			sprintf(buffer, "每次游轮上有[%d]个人，最后一次尽可能多带一些则游轮上有[%d]个人，游船出行次数{%d}，总计人数<%d>---总利润为:%d;\n", i, data, que.boat->_count, person_number, all_monery);
			fwrite(&buffer, strlen(buffer), 1, fp);
		}
		else
		{
			person_number = que.boat->_count * i;
			all_monery = person_number * person_monery - que.boat->_count * boat_monery;
			printf("每次游轮上有[%d]个人，船在岸边但是不够90人，游船出行次数{%d}，总计人数<%d>---总利润为:%d;\n", i, que.boat->_count, person_number, all_monery);
			sprintf(buffer, "每次游轮上有[%d]个人，船在岸边但是不够90人，游船出行次数{%d}，总计人数<%d>---总利润为:%d;\n", i, que.boat->_count, person_number, all_monery);
			fwrite(&buffer, strlen(buffer), 1, fp);
		}
	}
	system("pause");
}

void wait_much_boat_muchtime()
{
	Boat_queue que(3);
	int boat_monery = 0;
	int person_monery = 0;
	int all_monery;
	char buffer[1024] = { 0 };
	system("cls");
	printf("游轮需要维护的钱数：");
	std::cin >> boat_monery;
	printf("每一个人的船票：");
	std::cin >> person_monery;

	FILE* fp = fopen("./waitmuchboat.txt", "w");
	if (fp == NULL)
	{
		printf("文件打开失败!!!\n");
	}
	for (int i = 90; i <= PERSON_MAX; i += 3)
	{
		for (int j = 90; j <= PERSON_MAX; j += 3)
		{
			for (int z = 90; z <= PERSON_MAX; z += 3)
			{
				que.boat[0].chang_person(i);
				que.boat[0].chang_count(0);
				que.boat[0].chang_Boatcost(boat_monery);
				que.boat[1].chang_person(j);
				que.boat[1].chang_count(0);
				que.boat[1].chang_Boatcost(boat_monery);
				que.boat[2].chang_person(z);
				que.boat[2].chang_count(0);
				que.boat[2].chang_Boatcost(boat_monery);
				int person_number = 0;
				int boat1_time = i / 3;
				int boat2_time = j / 3;
				int boat3_time = z / 3;
				int all_time = ALL_TIME;
				int end_person = 0;
				int wait_time = 90;
				all_time = all_time - boat1_time - boat2_time - boat3_time + 10;
				que.boat[0].add_count();
				que.boat[1].add_count();
				que.boat[2].add_count();
				if ((boat1_time + boat2_time) >= 80 && (boat2_time + boat3_time) >= 80 && (boat3_time + boat1_time) >= 80)
				{
					while (all_time >= 50)
					{
						if (all_time > boat1_time)
						{
							que.boat[0].add_count();
							all_time -= boat1_time;
						}
						if (all_time > boat2_time)
						{
							que.boat[1].add_count();
							all_time -= boat2_time;
						}
						if (all_time > boat3_time)
						{
							que.boat[2].add_count();
							all_time -= boat3_time;
						}
					}
					if (all_time >= 30)
					{
						end_person = all_time * 3;
					}
					person_number = que.boat[0]._count * i + que.boat[1]._count * j + que.boat[2]._count * z + end_person;
					if (end_person)
					{
						if (que.boat[0]._count > que.boat[1]._count)
						{
							que.boat[1].add_count();
						}
						else if (que.boat[1]._count > que.boat[2]._count)
						{
							que.boat[2].add_count();
						}
						else
						{
							que.boat[0].add_count();
						}
					}
					int boat_num = que.boat[0]._count + que.boat[1]._count + que.boat[2]._count;
					all_monery = person_number * person_monery - boat_monery * boat_num;
					printf("第一艘游轮上有[%d]个人，第二艘游轮上有[%d]个人，第三艘游轮上有[%d]个人，第一个游轮出行次数{%d}，第二个游轮出行次数{%d}，第三个游轮出行次数{%d}，最后一次上了[%d]个人，总计人数<%d>---总利润为:%d;\n", i, j, z, que.boat[0]._count, que.boat[1]._count, que.boat[2]._count, end_person, person_number, all_monery);
					sprintf(buffer, "第一艘游轮上有[%d]个人，第二艘游轮上有[%d]个人，第三艘游轮上有[%d]个人，第一个游轮出行次数{%d}，第二个游轮出行次数{%d}，第三个游轮出行次数{%d}，最后一次上了[%d]个人，总计人数<%d>---总利润为:%d;\n", i, j, z, que.boat[0]._count, que.boat[1]._count, que.boat[2]._count, end_person, person_number, all_monery);
					fwrite(&buffer, strlen(buffer), 1, fp);
				}
				else
				{

					if ((boat1_time + boat2_time) >= 80)
					{
						if ((boat2_time + boat3_time) >= 80)
						{
							while (all_time >= 50)
							{
								if (all_time > boat1_time)
								{
									que.boat[0].add_count();
									all_time -= boat1_time;
								}
								if (all_time > boat2_time)
								{
									que.boat[1].add_count();
									all_time -= boat2_time;
									all_time = all_time - (90 - boat1_time - boat3_time - 10);
								}
								if (all_time > boat3_time)
								{
									que.boat[2].add_count();
									all_time -= boat3_time;
								}
							}
							if (all_time >= 30)
							{
								end_person = all_time * 3;
							}
							person_number = que.boat[0]._count * i + que.boat[1]._count * j + que.boat[2]._count * z + end_person;
							if (end_person)
							{
								if (que.boat[0]._count > que.boat[1]._count)
								{
									que.boat[1].add_count();
								}
								else if (que.boat[1]._count > que.boat[2]._count)
								{
									que.boat[2].add_count();
								}
								else
								{
									que.boat[0].add_count();
								}
							}
							int boat_num = que.boat[0]._count + que.boat[1]._count + que.boat[2]._count;
							all_monery = person_number * person_monery - boat_monery * boat_num;
							printf("第一艘游轮上有[%d]个人，第二艘游轮上有[%d]个人，第三艘游轮上有[%d]个人，第一个游轮出行次数{%d}，第二个游轮出行次数{%d}，第三个游轮出行次数{%d}，最后一次上了[%d]个人，总计人数<%d>---总利润为:%d;\n", i, j, z, que.boat[0]._count, que.boat[1]._count, que.boat[2]._count, end_person, person_number, all_monery);
							sprintf(buffer, "第一艘游轮上有[%d]个人，第二艘游轮上有[%d]个人，第三艘游轮上有[%d]个人，第一个游轮出行次数{%d}，第二个游轮出行次数{%d}，第三个游轮出行次数{%d}，最后一次上了[%d]个人，总计人数<%d>---总利润为:%d;\n", i, j, z, que.boat[0]._count, que.boat[1]._count, que.boat[2]._count, end_person, person_number, all_monery);
							fwrite(&buffer, strlen(buffer), 1, fp);
						}
						else
						{
							while (all_time >= 50)
							{
								if (all_time > boat1_time)
								{
									que.boat[0].add_count();
									all_time -= boat1_time;
									all_time = all_time - (90 - boat2_time - boat3_time - 10);
								}
								if (all_time > boat2_time)
								{
									que.boat[1].add_count();
									all_time -= boat2_time;
								}
								if (all_time > boat3_time)
								{
									que.boat[2].add_count();
									all_time -= boat3_time;
								}
							}
							if (all_time >= 30)
							{
								end_person = all_time * 3;
							}
							person_number = que.boat[0]._count * i + que.boat[1]._count * j + que.boat[2]._count * z + end_person;
							if (end_person)
							{
								if (que.boat[0]._count > que.boat[1]._count)
								{
									que.boat[1].add_count();
								}
								else if (que.boat[1]._count > que.boat[2]._count)
								{
									que.boat[2].add_count();
								}
								else
								{
									que.boat[0].add_count();
								}
							}
							int boat_num = que.boat[0]._count + que.boat[1]._count + que.boat[2]._count;
							all_monery = person_number * person_monery - boat_monery * boat_num;
							printf("第一艘游轮上有[%d]个人，第二艘游轮上有[%d]个人，第三艘游轮上有[%d]个人，第一个游轮出行次数{%d}，第二个游轮出行次数{%d}，第三个游轮出行次数{%d}，最后一次上了[%d]个人，总计人数<%d>---总利润为:%d;\n", i, j, z, que.boat[0]._count, que.boat[1]._count, que.boat[2]._count, end_person, person_number, all_monery);
							sprintf(buffer, "第一艘游轮上有[%d]个人，第二艘游轮上有[%d]个人，第三艘游轮上有[%d]个人，第一个游轮出行次数{%d}，第二个游轮出行次数{%d}，第三个游轮出行次数{%d}，最后一次上了[%d]个人，总计人数<%d>---总利润为:%d;\n", i, j, z, que.boat[0]._count, que.boat[1]._count, que.boat[2]._count, end_person, person_number, all_monery);
							fwrite(&buffer, strlen(buffer), 1, fp);
						}
					}
					else
					{
						while (all_time >= 50)
						{
							if (all_time > boat1_time)
							{
								que.boat[0].add_count();
								all_time -= boat1_time;
							}
							if (all_time > boat2_time)
							{
								que.boat[1].add_count();
								all_time -= boat2_time;
							}
							if (all_time > boat3_time)
							{
								que.boat[2].add_count();
								all_time -= boat3_time;
								all_time = all_time - (90 - boat1_time - boat2_time - 10);
							}
						}
						if (all_time >= 30)
						{
							end_person = all_time * 3;
						}
						person_number = que.boat[0]._count * i + que.boat[1]._count * j + que.boat[2]._count * z + end_person;
						if (end_person)
						{
							if (que.boat[0]._count > que.boat[1]._count)
							{
								que.boat[1].add_count();
							}
							else if (que.boat[1]._count > que.boat[2]._count)
							{
								que.boat[2].add_count();
							}
							else
							{
								que.boat[0].add_count();
							}
						}
						int boat_num = que.boat[0]._count + que.boat[1]._count + que.boat[2]._count;
						all_monery = person_number * person_monery - boat_monery * boat_num;
						printf("第一艘游轮上有[%d]个人，第二艘游轮上有[%d]个人，第三艘游轮上有[%d]个人，第一个游轮出行次数{%d}，第二个游轮出行次数{%d}，第三个游轮出行次数{%d}，最后一次上了[%d]个人，总计人数<%d>---总利润为:%d;\n", i, j, z, que.boat[0]._count, que.boat[1]._count, que.boat[2]._count, end_person, person_number, all_monery);
						sprintf(buffer, "第一艘游轮上有[%d]个人，第二艘游轮上有[%d]个人，第三艘游轮上有[%d]个人，第一个游轮出行次数{%d}，第二个游轮出行次数{%d}，第三个游轮出行次数{%d}，最后一次上了[%d]个人，总计人数<%d>---总利润为:%d;\n", i, j, z, que.boat[0]._count, que.boat[1]._count, que.boat[2]._count, end_person, person_number, all_monery);
						fwrite(&buffer, strlen(buffer), 1, fp);

					}
				}
			}
		}
	}
	system("pause");
}

int main()
{
	int i;
	do
	{
		system("cls");
		meun();
		printf("请选择你要分析的情况：");
		std::cin >> i;
		switch (i)
		{
		case 1:
			one_boat_muchtime();
			break;
		case 0:
			printf("轮船分析已退出\n");
			break;
		case 2:
			much_boat_muchtime();
			break;
		case 3:
			wait_one_boat_muchtime();
			break;
		case 4:
			wait_much_boat_muchtime();
			break;
		default:
			break;
		}
	} while (i);
	system("pause");
	return 0;
}