#include <stdio.h>
#include <math.h>

double AttackerSuccessProbability(double q, int z);

int main()
{
  double q = 0.1;
  printf("q = %.2lf\n", q);
  double proba = 0.0;
  
  int z = 0;
  for (z = 0; z < 11; z++)
  {
    proba = AttackerSuccessProbability(q, z);
    printf("z = %d\tP = %.7lf\n", z, proba);
  }
  q = 0.3;
  printf("q = %.2lf\n", q);
  for (z = 0; z < 51; z += 5)
  {
    proba = AttackerSuccessProbability(q, z);
    printf("z = %d\tP = %.7lf\n", z, proba);
  }
  printf("\n===============================\n\n");
  printf("P < 0.001\n");
  printf("---------\n\n");
  q = 0.1; z = 5;
  proba = AttackerSuccessProbability(q, z);
  printf("(\tq = %.2lf\tz = %d\t)\t=>\tP = %.4lf\n", q, z, proba);

  q = 0.15; z = 8;
  proba = AttackerSuccessProbability(q, z);
  printf("(\tq = %.2lf\tz = %d\t)\t=>\tP = %.4lf\n", q, z, proba);

  q = 0.2; z = 11;
  proba = AttackerSuccessProbability(q, z);
  printf("(\tq = %.2lf\tz = %d\t)\t=>\tP = %.4lf\n", q, z, proba);
  
  q = 0.25; z = 15;
  proba = AttackerSuccessProbability(q, z);
  printf("(\tq = %.2lf\tz = %d\t)\t=>\tP = %.4lf\n", q, z, proba);

  q = 0.3; z = 24;
  proba = AttackerSuccessProbability(q, z);
  printf("(\tq = %.2lf\tz = %d\t)\t=>\tP = %.4lf\n", q, z, proba);

  q = 0.35; z = 41;
  proba = AttackerSuccessProbability(q, z);
  printf("(\tq = %.2lf\tz = %d\t)\t=>\tP = %.4lf\n", q, z, proba);

  q = 0.4; z = 89;
  proba = AttackerSuccessProbability(q, z);
  printf("(\tq = %.2lf\tz = %d\t)\t=>\tP = %.4lf\n", q, z, proba);

  q = 0.45; z = 340;
  proba = AttackerSuccessProbability(q, z);
  printf("(\tq = %.2lf\tz = %d\t)\t=>\tP = %.4lf\n", q, z, proba);

}

double AttackerSuccessProbability(double q, int z)
{
  double p = 1.0 - q;
  double lambda = z * (q / p);
  double sum = 1.0;
  int i, k;
  for (k = 0; k <= z; k++)
  {
    double poisson = exp(-lambda);
    for (i = 1; i <= k; i++)
      poisson *= lambda / i;
    sum -= poisson * (1 - pow(q / p, z - k));
  }
  return sum;
}
