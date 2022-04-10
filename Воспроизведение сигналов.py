#!/usr/bin/env python
# coding: utf-8

# In[10]:


import sys

get_ipython().system('{sys.executable} -m pip install sounddevice')
get_ipython().system('{sys.executable} -m pip install numpy')

import numpy as np


# In[ ]:


duration = 0.7  # длительность сигнала в секундах
amplitude = 0.3  # амплитуда  (в пределах: +-1.0)
frequency = 1500  # частота сигнала в [Гц]
# т.к. невозможно программно организовать аналоговый сигнал, необходимо обозначить
fs = 50000 # 80 тыс. временных отсчетов в 1 секунду количество временных отчетов, т.е. частоту дискретизации (об этом чуть позже)


# In[ ]:


timeSamples = np.arange(np.ceil(duration * fs)) / fs
timeSamples
#channels ( signal2 , signal3 , signal4 , signal5)


# In[160]:


signal = amplitude * np.sin(2 * np.pi * frequency * timeSamples)
signal


# In[ ]:





# In[ ]:





# In[161]:


import sounddevice as sd


# In[ ]:





# In[162]:


signal2 = amplitude * np.sin(2 * np.pi * 550 * timeSamples)
signal3 = amplitude * np.sin(2 * np.pi * 660 * timeSamples)
signal4 = amplitude * np.sin(2 * np.pi * 770 * timeSamples)
signal5 = amplitude * np.sin(2 * np.pi * 880 * timeSamples)
signal6 = amplitude * np.sin(2 * np.pi * 990 * timeSamples)
signal7 = amplitude * np.sin(2 * np.pi * 1100 * timeSamples)
signal8 = amplitude * np.sin(2 * np.pi * 1300 * timeSamples)


#np.channels ( signal2 , signal3 , signal4 , signal5)


# In[163]:


plt.plot(timeSamples[:2000] * 1000, signalSumm[:2000])
plt.title("sine tone")
plt.xlabel("time / milliseconds")


# In[169]:


sd.play(signal2, fs, None, 1)
sd.play(signal2, fs, None, 1)
sd.play(signal4, fs, None, 1)
sd.play(signal4, fs, None, 1)
sd.play(signal6, fs, None, 1)
sd.play(signal6, fs, None, 1)
sd.play(signal5, fs, None, 1)
sd.play(signal3, fs, None, 1)
sd.play(signal3, fs, None, 1)
sd.play(signal7, fs, None, 1)
sd.play(signal7, fs, None, 1)


# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:




