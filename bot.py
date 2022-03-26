import discord
from discord.ext import commands
import serial

arduino = serial.Serial('/dev/ttyACM0', 9600)

bot = commands.Bot(command_prefix=".")


@bot.event
async def on_ready():
    print("bot is ready")
    
    
@bot.command()
async def temp(ctx):
    arduino.write(b't')
    t = arduino.readline()
    print(t.decode().strip())
    await ctx.send(t.decode().strip())
    
    
@bot.command()
async def hum(ctx):
    arduino.write(b'h')
    h = arduino.readline()
    print(h.decode().strip())
    await ctx.send(h.decode().strip())


@bot.command()
async def lighton(ctx):
    arduino.write(b'o')
    await ctx.send("light is on")

@bot.command()
async def lightoff(ctx):
    arduino.write(b'f')
    await ctx.send("light is off")
    
@bot.command()
async def carbon(ctx):
    arduino.write(b'c')
    c = arduino.readline()
    print(c.decode().strip())
    await ctx.send(c.decode().strip())
    
'''
@bot.command()
async def lux(ctx):
    arduino.write(b'l')
    l = arduino.readline()
    print(l.decode().strip())
    await ctx.send(l.decode().strip())
'''
    
bot.run("OTUyMDcxMjU2NDE1NTYzODQ2.YiwrdA.DcDSq-OQpAjMbrApjKPGHK9Z7d4")