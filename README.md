# Prog 5: SpeechGrade

3/21 Modified rules to only subtract one for adjacent vowels inside a word, to properly handle words like "flea".  Also combined rules 3 & 4 into an "if-else" rule to avoid subtracting two times for a word ending in "le". Hyphens ('-') should also separate words.  The letter 'Y' now counts as a vowel.

According to a October 20, 2015 Boston Globe article, Trump's presidential announcement speech "could have been comprehended by a fourth-grader" according to an algorithm called the Flesch-Kincaid (F-K) grade level test.  News articles are sometimes inflammatory, prone to exaggeration for the sake of generating interest.  So, is the claim about Trump's speech true?  How does Trump's presidential announcement speech compare to other candidates' announcement speeches? (Note that this is a separate issue from whether or not simpler is better!)

Comparing these speeches is our task for this assignment.  Take the recent presidential announcement speeches and print out a table of them according to the F-K grade level test, with the lowest grade level at the top of the list, and the highest grade-level at the bottom.  You should be able to compare your results at readability-score.com.  The F-K test (from this wikipedia page) is:

** The rest of the description is on https://sites.google.com/site/uic141spring2016/prog-5-speechgrade **
