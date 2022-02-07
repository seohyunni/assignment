from discord import activity
import discord, asyncio, os
from discord.ext import commands

TOKEN = '##'
CHANNEL_ID = 0

online = discord.Game("Cyphers")
bot = commands.Bot(command_prefix = '!', status = discord.Status.online)
client = discord.Client()

@bot.command(aliases = ['hello', '안녕', 'hi'])
async def Hello(ctx):
  await ctx.send(f'{ctx.author.mention} 안녕하세요?')

@bot.command(aliases = ['ilang','이랑', '김이랑'])
async def Ilang(ctx):
  await ctx.send(f'{ctx.author.mention} 뭐요')

@bot.command(aliases = ['럄', '구승민', '개발자'])
async def ryam(ctx):
  await ctx.send(f'{ctx.author.mention} 샆손실 난다 접속해라')

@bot.command(aliases = ['정사부', '강규혁', '삽'])
async def sap(ctx):
  await ctx.send(f'{ctx.author.mention} 귀여운 감자 라이언')

@bot.command(aliases = ['왕밤빵','밤빵','송인혁'])
async def bread(ctx):
  await ctx.send(f'{ctx.author.mention} 내안의 송인혁 더 거침없이')

@bot.command(aliases = ['넻', '이끼', '이끼끼'])
async def boots(ctx):
  await ctx.send(f'{ctx.author.mention} 이끼로 2행시 해봄')

@bot.command(aliases = ['빠리', '뇸', '뿡'])
async def taxi(ctx):
  await ctx.send(f'{ctx.author.mention} 어쩌라고 이 대머리야')

@bot.command(aliases = ['배지우', '배지w', 'w'])
async def bae(ctx):
  await ctx.send(f'{ctx.author.mention} 배지더블유 웃기면 한 건 했다')

@bot.command(aliases = ['냐냐', '다미', '예나'])
async def idol(ctx):
  await ctx.send(f'{ctx.author.mention} 명진빌라 아이돌')

@bot.command(aliases = ['c', '사퍼', '사이퍼즈'])
async def cyphers(ctx):
  await ctx.send(f'{ctx.author.mention} 님만 오면 5인팟')

@bot.command(aliases =['h', '도움'])
async def x(ctx) :
  embed = discord.Embed(title = '명진빌라 봇', description = '명진빌라만의 디스코드 봇이에요 >.ㅇ', color=0x4432a8)
  embed.add_field(name = '1. 인사', value = '!hello or !안녕 or !hi', inline=False)
  embed.add_field(name = '2. 김이랑', value = '!ilang or !이랑 or !김이랑', inline=False)
  embed.add_field(name = '3. 럄', value = '!럄 or !구승민 or !개발자', inline=False)
  embed.add_field(name = '4. 정사부', value = '!정사부 or !강규혁 or !삽', inline=False)
  embed.add_field(name = '5. 왕밤빵', value = '!왕밤빵 or !밤빵 or !송인혁', inline=False)
  embed.add_field(name = '6. 이끼', value = '!넻 or !이끼 or !이끼끼', inline=False)
  embed.add_field(name = '7. 빠리', value = '!빠리 or !뇸 or !뿡', inline=False)
  embed.add_field(name = '8. 배지터', value = '!배지우 or !배지w or !w', inline=False)
  embed.add_field(name = '9. 냐냐', value = '!냐냐 or !다미 or !예나', inline=False)
  embed.add_field(name = '10. 사이퍼즈', value = '!cyphers or !c or !사퍼 or !사이퍼즈', inline=False)
  await ctx.send(embed = embed)

bot.run(TOKEN)