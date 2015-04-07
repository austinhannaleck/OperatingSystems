import java.util.concurrent.*;

public class ThreadPoolExample 
{  
     public static void main(String[] args) 
     {  
        ExecutorService executor = Executors.newFixedThreadPool(5);
        for (int i = 0; i < 10; i++) 
        {  
            WorkerThread worker = new WorkerThread(i);  
            executor.execute(worker); 
        }  
        executor.shutdown();

        while (!executor.isTerminated()) 
        { 
          try
          {
            Thread.sleep(100); 
          }
          catch (Exception e)
          {} 
        }  
  
        System.out.println("Finished all threads");  
    }  
}

class WorkerThread implements Runnable
{
  public WorkerThread(int i)
  {
    m_i = i;
  }

  public void run()
  {
    for (int i = 0; i < 10; i++)
    {
      System.out.println("Hello from thread " + m_i);
    }
  }

  private int m_i;
}  