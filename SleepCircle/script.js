const bedtimeInput = document.getElementById("bedtime");
const setBtn = document.getElementById("setBtn");
const progress = document.getElementById("progress");
const status = document.getElementById("status");
const tip = document.getElementById("tip");

const tips = [
  "Avoid screens 30 minutes before sleep.",
  "Keep your room cool and dark.",
  "Stick to a consistent bedtime.",
  "Relax with deep breathing.",
  "Limit caffeine in the evening."
];

function updateProgress() {
  const bedtime = bedtimeInput.value;
  if (!bedtime) return;

  const now = new Date();
  const [hours, minutes] = bedtime.split(":").map(Number);
  const bedtimeDate = new Date();
  bedtimeDate.setHours(hours, minutes, 0);

  const totalMinutes = 24 * 60;
  let passedMinutes = now.getHours() * 60 + now.getMinutes();

  let progressPercent = (passedMinutes / totalMinutes) * 100;
  progress.style.height = `${progressPercent}%`;

  status.textContent = `Your bedtime is at ${bedtime} 🌙`;
  tip.textContent = tips[Math.floor(Math.random() * tips.length)];
}

setBtn.addEventListener("click", updateProgress);

// Optional: update progress every minute
setInterval(updateProgress, 60000);
