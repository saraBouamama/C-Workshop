
void cipher(const char *key, const char *msg, char *res)
{
    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < msg; j++)
        {
            while (msg[i] <= 122 && msg[i] > 66)
            {
                msg[i] = key[j];
            }
            msg[i] = (msg[i] + key[j]) % 26;
        }
    }
}

void decipher(const char *key, const char *msg, char *res) for (int i = 0;
                                                                i < key[]; i++)
{
    for (int j = 0; j < msg[]; j++)
    {
        while (msg[i] <= 122 && msg[i] > 66)
        {
            msg[i] = key[j];
        }
        msg[i] = (msg[i] - key[j]) % 26;
    }
}
}
