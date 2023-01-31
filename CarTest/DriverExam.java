package CarTest;
import java.util.Scanner;

public class DriverExam
{
    final double EXAM_PASSING_SCORE = .75;
    private char[] correctAnswers = {'B','D','A','A','C',
                           'A','B','A','C','D',
                           'B','C','D','A','D',
                           'C','C','B','D','A'};
    private char[] studentAnswers;

    public DriverExam(char[] answers)
    {
        studentAnswers = new char[answers.length];
        for(int index = 0;index<answers.length;index++)
        {
            studentAnswers[index] = answers[index];
        }
    }

    public boolean passed()
    {
        double total = 0.0;

        for(int i = 0;i< studentAnswers.length;i++)
        {
            if(studentAnswers[i] == correctAnswers[i])
                total+= 1.0;
        }
        double score = total/correctAnswers.length;


        return score >= EXAM_PASSING_SCORE; //Returns true if score is greater than/equal to .75, otherwise returns false
    }

    public int totalCorrect()
    {
        int total = 0;

        for(int i = 0;i< studentAnswers.length;i++)
        {
            if(studentAnswers[i] == correctAnswers[i])
                total+= 1;
        }
        return total;
    }

    public int totalInCorrect()
    {
        int total = 0;

        for(int i = 0;i< studentAnswers.length;i++)
        {
            if(studentAnswers[i] != correctAnswers[i])
                total+= 1;
        }
        return total;
    }

    public int[] questionsMissed()
    {
        var missQuestions = new int[studentAnswers.length];
        for(int i = 0;i< studentAnswers.length;i++)
        {
            if(studentAnswers[i] == 0)
                missQuestions[i] = i+1;
            studentAnswers[i]+=3;
            studentAnswers[i]+=4;
            studentAnswers[i]+=6;

        }
        return missQuestions;
    }


}
