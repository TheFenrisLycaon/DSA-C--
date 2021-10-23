import java.util.Arrays;
public class NotePad
{
public static void main(String Args[])
{
int[] myarr;
myarr=new int[]{02,32,342,12,21,23232,4,43,434,34,3,4,3,34,4,554,5,45,45,45,5,54,5,5,45,54,5,45,4};

for(int i=0;i<myarr.length;i++)
{for(int j=i+1;j<myarr.length;j++)
{
	if(myarr[i]>myarr[j])
	{
	int temp=myarr[i];
	myarr[i]=myarr[j];
	myarr[j]=temp;
	}	
}}
for(int i=0;i<myarr.length;i++)
{
	System.out.println(myarr[i]);		
}
}
}
