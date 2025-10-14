# -*- coding: utf-8 -*-
"""
Created on Fri Jan 27 16:25:27 2023

@author: HP
"""

import pickle
import numpy as np
import streamlit as st

#loaded the machine learning model
loaded_model = pickle.load(open('heart_disease_trained_model.sav','rb'))

#creating a function for Prediction
def heart_disease_prediction(input_data):
    # changing the input_data to numpy array
    input_data_as_numpy_array = np.asarray(input_data)

    # reshape the array as we are predicting for one instance
    input_data_reshaped = input_data_as_numpy_array.reshape(1,-1)

    prediction = loaded_model.predict(input_data_reshaped)
    print(prediction)

    if (prediction[0] == 0):
      return 'The person does not have a heart disease'
    else:
      return 'The person does have a heart disease'

def main():
    
    #giving a title
    st.title('Heart Disease Prediction Web App')
    
    #getting input from the user
    Age = st.text_input('Age')
    Sex = st.text_input('Sex (1->Male, 0->Female)')
    Cp = st.text_input('Chest Pain Type(0,1,2,3)')
    trestbps = st.text_input('Resting Blood Pressure (in mm Hg on admission to the hospital)')
    chol = st.text_input('Serum Cholestral in mg/dl')
    fbs = st.text_input('Fasting Blood Sugar (1->True, 0->False)')
    restecg = st.text_input('Resting Electrocardiographic Results')
    thalach = st.text_input('Maximum Heart Rate achieved')
    exang = st.text_input('Exercise Induced Angina (1 = yes; 0 = no)')
    oldpeak = st.text_input('ST depression induced by exercise relative to rest')
    slope = st.text_input('The Slope of the peak exercise ST segment')
    ca = st.text_input('Number of major vessels (0-3) colored by flourosopy')
    thal = st.text_input('1 = Normal; 2 = Fixed defect; 3 = Reversable defect')

    
    #code for prediction
    diagnosis = ''
    
    # getting the input data from the user
    if st.button('Heart Disease Test Result : '):
        diagnosis = heart_disease_prediction([Age,Sex,Cp,trestbps,chol,fbs,restecg,thalach,exang,oldpeak,slope,ca,thal])
        
    st.success(diagnosis)

if __name__ == "__main__":
    main()
