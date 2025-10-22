## How to get user-session-token is to login in your browser and inspect and find the user-session-token and replace it in script for local

import winsound
import pygame
import threading
import discord
from discord.ext import commands
from playsound import playsound

TOKEN = "user-session-token-here"
TARGET_USER_ID = 123456789012345678  # Replace with the target user's ID
SOUND_PATH = "V:/summon.mp3" # Path to your alert sound file

bot = commands.Bot(command_prefix="!", self_bot=True)
import winsound

def play_sound():
    try:
        winsound.PlaySound(SOUND_PATH, winsound.SND_FILENAME)
    except Exception as e:
        print(f"[Sound Error]: {e}")


@bot.event
async def on_ready():
    print(f"[INFO] Logged in as {bot.user}")

@bot.event
async def on_message(message):
    if isinstance(message.channel, discord.DMChannel) and message.author.id == TARGET_USER_ID:
        print(f"[ALERT] DM from {message.author.name}: {message.content}")
        threading.Thread(target=play_sound).start()

bot.run(TOKEN)
