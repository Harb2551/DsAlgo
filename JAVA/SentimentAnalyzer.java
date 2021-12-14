import java.util.Arrays;

public class SentimentAnalyzer {
    // Tip: labeled continue can be used when iterating featureSet + convert review tower-case
	public static int[] detectProsAndCons(String review, String[][] featureSet, String[] posOpinionWords,
			String[] negOpinionWords) {
		int[] featureOpinions = new int[featureSet.length]; // output
        int k,x=0;
        // your code ~ you will be invoking getOpinionOnFeature		
        w:for (String i[]:featureSet){
            for (int  j = 0; j < i.length; j++){
                k = getOpinionOnFeature(review,i[j],posOpinionWords,negOpinionWords);
                if (j == i.length - 1){
                    featureOpinions[x++] = k;
                    continue w;
                }
                if (k != 0){
                    featureOpinions[x++] = k;
                    continue w;
                }
            }
        }
		return featureOpinions;
	}

	// First invoke checkForWasPhrasePattern and 
	// if it cannot find an opinion only then invoke checkForOpinionFirstPattern
	private static int getOpinionOnFeature(String review, String feature, String[] posOpinionWords, String[] negOpinionWords) {
		
		// your code
		int r = checkForWasPhrasePattern(review,feature,posOpinionWords,negOpinionWords);
		if (r == 0){
		    r = checkForOpinionFirstPattern(review,feature,posOpinionWords,negOpinionWords);
		}
		return r;
		
	}	

	// Tip: Look at String API doc. Methods like indexOf, length, substring(beginIndex), startsWith can come into play
	// Return 1 if positive opinion found, -1 for negative opinion, 0 for no opinion
	// You can first look for positive opinion. If not found, only then you can look for negative opinion
	private static int checkForWasPhrasePattern(String review, String feature, String[] posOpinionWords, String[] negOpinionWords) {
		int p = 0,q = 0,opinion = 0;
		String pattern = feature + " was ";
        if (review.contains(pattern)){
            for (String i : posOpinionWords){
               if (review.contains(i)){
                   opinion = 1;
                   break;
               }
            }
            if (opinion != 1){
              for (String i : negOpinionWords){
                    if (review.contains(i)){
                      opinion = -1;
                      break;
                    }
            }
           }
        }
      return opinion; 	
	}
	
	// You can first look for positive opinion. If not found, only then you can look for negative opinion
	private static int checkForOpinionFirstPattern(String review, String feature, String[] posOpinionWords,
			String[] negOpinionWords) {
		// Extract sentences as feature might appear multiple times. 
		// split() takes a regular expression and "." is a special character 
		// for regular expression. So, escape it to make it work!!
		String[] sentences = review.split(" ");
		int opinion = 0;
		
		// your code for processing each sentence. You can return if opinion is found in a sentence (no need to process subsequent ones)
		
		  s:for (int  i = 0; i < sentences.length; i++){
		     // String[] word = i.split(" ");
		     for (String j: posOpinionWords){
		       // for (int k = 0;k < word.length; k++){
		            if (sentences[i].contains(j) && sentences[i+1].contains(feature)){
		                  opinion = 1;
		                  break s;
		                    }
		                }
		                // }
		           }
		           
		   if (opinion != 1){
		     y:for (int i = 0 ; i < sentences.length; i++){
		     // String[] word = i.split(" ");
		      for (String j: negOpinionWords){
		       // for (int k = 0;k < word.length; k++){
		            if (sentences[i].contains(j) && sentences[i+1].contains(feature)){
		                  opinion = -1;
		                  break y;
		                    }
		                }
		                // }
		           }
		      }
		
		return opinion;
	}

	public static void main(String[] args) {
		String review = "Haven't been here in years! Fantastic service and the food was delicious! Definetly will be a frequent flyer! Francisco was very attentive";
		
		//String review = "Sorry OG, but you just lost some loyal customers. Horrible service, no smile or greeting just attitude. The breadsticks were stale and burnt, appetizer was cold and the food came out before the salad.";
		
		String[][] featureSet = { 
		        { "ambiance", "ambience", "atmosphere", "decor" },
				{ "dessert", "ice cream", "desert" }, 
				{ "food" }, 
				{ "soup" },
				{ "service", "management", "waiter", "waitress", "bartender", "staff", "server" } };
		String[] posOpinionWords = { "good", "Fantastic", "friendly", "great", "excellent", "amazing", "awesome",
				"delicious" };
		String[] negOpinionWords = { "slow", "bad", "horrible", "awful", "unprofessional", "poor" };

		int[] featureOpinions = detectProsAndCons(review, featureSet, posOpinionWords, negOpinionWords);
		System.out.println("Opinions on Features: " + Arrays.toString(featureOpinions));
	}
}