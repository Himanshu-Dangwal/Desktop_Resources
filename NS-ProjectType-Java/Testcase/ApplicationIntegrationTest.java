package com.newtonschool.question;

import static org.junit.Assert.*;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.PrintStream;

import org.junit.Assert;
import org.junit.Test;

public class ApplicationIntegrationTest {

    @Test
    public void testReadFile() throws IOException {
        // Redirect System.out to capture printed output
        ByteArrayOutputStream outContent = new ByteArrayOutputStream();
        System.setOut(new PrintStream(outContent));

        Application.readFromFile("dummy.txt");

        // Expected content of dummy.txt
        String expectedContent = "Hello My name is Himanshu Dangwal";

        // Assert that the printed output matches the expected content
        Assert.assertEquals(expectedContent, outContent.toString().trim());
    }
    
    @Test
    public void testFirstWord() throws IOException {
        // Redirect System.out to capture printed output
        ByteArrayOutputStream outContent = new ByteArrayOutputStream();
        System.setOut(new PrintStream(outContent));

        Application.readFromFile("dummy.txt");

        // Expected first word of dummy.txt
        String expectedFirstWord = "Hello";

        // Get the printed output and split it into words
        String[] words = outContent.toString().trim().split("\\s+");

        // Assert that the first word matches the expected first word
        Assert.assertEquals(expectedFirstWord, words[0]);
    }
}
