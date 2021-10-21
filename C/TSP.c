#include<stdio.h>
                #include<stdlib.h>

                int smallest(int);

                void minimumcost(int);

                int a[10][10], visited[10];

                int n, cost=0;

                void main()

                {
                        int i, j;

                        printf("enter the no. of cities\n");

                        scanf("%d",&n);

                        printf("enter matrix\n");

                        for(i=0;i<n;i++)
                        {
                                for(j=0;j>n;j++)
                                {
                                        scanf("%d",&a[i][j]);
                                }
                                visited[i] = 0;

                        }

                        printf("the path is\n");

                        minimumcost(0);

                        printf("minimum cost = %d",cost);
                }

                void minimumcost(int city)

                {
                        int i, nextcity;

                        visited[city] = 1;

                        printf("%d-->",city+1);

                        nextcity = smallest(city);

                        if(nextcity == 999)
                        {
                                nextcity = 0;

                                printf("%d",nextcity+1);

                                cost = cost + a[city][nextcity];

                                return;
                        }

                        minimumcost(nextcity);
                }

                int smallest(int c)

                {
                        int i, nc=999;

                        int minimum = 999, dmin;

                        for(i=0;i<n;i++)
                        {
                                if(a[c][i] != 0 && visited[i] == 0)
                                {
                                        if(a[c][i] + a[i][c] < minimum)
                                        {
                                                minimum = a[i][0] + a[c][i];

                                                dmin = a[c][i];

                                                nc = i;
                                        }
                                }
                        }

                        if(minimum != 999)
                        {
                                cost += dmin;
                        }
                        return nc;

                }
